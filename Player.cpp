#include "Player.h"

int Player::maxHealth = 10;

Player::Player()
{
    std::cout << "Initializing player...\n";
    std::cout << "Player's name (<= 100 characters): \n";
    name = safeString(100);

    std::cout << "Coordinates of a player: (" << x << "; " << y <<")\n";


    std::cout << "Enter the initial health of the player ";
    health = safeInt(1,10);


    std::cout << "Enter the speed of the player ";
    speed= safeInt(1, 10);

    std::cout << "Enter the damage of the player ";
    damage = safeInt(1, 2);



    potions_count = 0; // ������������� �� ���������
    is_alive = true;   // ����� ��� ��� ��������
    coins = 0;         // ��������� ���������� �����

    std::cout << "Player " << name << " initialized successfully!\n";
}

// ���������� ������
Player& Player::movePlayer(int x, int y) {
    this->x += x;
    this->y += y;
    printf("Player moved to (%d, %d)\n", this->x, this->y);
    return *this;
}

void Player::printCoordinates() {
    std::cout << "Player is at (" << x << ", " << y << ")\n";
}

// ���������, ���� �� �����
bool Player::isAlive() {
    return is_alive;

}
Inventory Player::getInventory() {
    return inventory;
}


void Player::add_coins(int value) { coins += value; }
int Player::get_coins() { return coins; }
int& Player::getX() { return x; }
int& Player::getY() { return y; }
int Player::getspeed() { return speed; }
// ������� �������� �������������� ������
void Player::printPlayer()
{
    printf("Player Position: (%d, %d)\n", x, y);
    printf("Health: %d/%d\n", health, Player::maxHealth);
    printf("Speed: %d\n", speed);
    printf("Player inventory space: %d, items count: %d\n", inventory.getSpace(), inventory.getItemsCount());
    printf("Player coins: %d\n", coins);
} // ����� ������

int Player::getCurrentHealth() {
    return health;
}

// ������ �������� �������� �������� ������ (��������, ��� ����� � �������� �� ������ ��������)
void Player::changeHealthValue(int new_value) {
    health = new_value;
}

void Player::heal(int value) {
    health += value;
}
int Player::getDamage() { return damage; }

void Player::is_dead() { is_alive = false; }


void Player::addItems(Item* item)
{
    inventory.inventoryAddItem(item);
}

int Player::getItemsCount() {
   return  inventory.getItemsCount();
}

Item* Player::getItem(const std::string& itemName) {
    Item*** items = inventory.getInventoryItems();
    for (int i = 0; i < Inventory::getSpace(); i++) {
        for (int j = 0; j < Inventory::getSpace(); j++) {
            std::cout << "Item [" << i + 1 << ";" << j+1 << "]" << items[i][j]->getName() << ", Damage: " << items[i][j]->getDamage() << std::endl;
            if (items[i][j]->getName().find(itemName) != std::string::npos) return items[i][j];
        }

    }
 
    return nullptr;
}


void Player::setMaxHealth(int value) {
    Player::maxHealth = value;
}


int Player::getMaxHealth() {
    return maxHealth;
}

std::string Player::getName() {
    return name;
}