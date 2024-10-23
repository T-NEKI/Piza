#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Item {
    string name;
    int price;
};

int main() {
    setlocale(LC_ALL, "Russian");
    const int PIZZA_COUNT = 7;
    const int SNACK_COUNT = 4;
    const int DRINK_COUNT = 5;

    const int DRINK_DISCOUNT_THRESHOLD = 100;
    const int ORDER_DISCOUNT_THRESHOLD = 1000;

    array<Item, PIZZA_COUNT> pizzas = { {
        {"Маргарита", 300},
        {"Пепперони", 350},
        {"Гавайская", 400},
        {"Четыре сыра", 450},
        {"Вегетарианская", 300},
        {"Мясная", 500},
        {"Супер Сырная", 550}
    } };

    array<Item, SNACK_COUNT> snacks = { {
        {"Картофель фри", 100},
        {"Куриные крылышки", 200},
        {"Сырные палочки", 150},
        {"Гарлик дип", 50}
    } };

    array<Item, DRINK_COUNT> drinks = { {
        {"Кола", 80},
        {"Сок", 90},
        {"Минеральная вода", 50},
        {"Чай", 60},
        {"Кофе", 110}
    } };

    while (true) {
        int pizzaChoice = -1, snackChoice = -1, drinkChoice = -1;
        int totalCost = 0;
        int pizzaCount = 0;
        int fancyDrinks = 0;

      
        cout << "**Выберите пиццу** (-1 для отмены):\n";
        for (int i = 0; i < PIZZA_COUNT; ++i) {
            cout << i + 1 << ". " << pizzas[i].name << " - " << pizzas[i].price << " руб.\n";
        }

        while (cin >> pizzaChoice && pizzaChoice != -1) {
            if (pizzaChoice > 0 && pizzaChoice <= PIZZA_COUNT) {
                totalCost += pizzas[pizzaChoice - 1].price;
                pizzaCount++;
                if (pizzaCount % 5 == 0) {
                    totalCost -= pizzas[pizzaChoice - 1].price;
                }
            }
            else {
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }

        cout << "**Выберите закуску** (-1 для отмены):\n";
        for (int i = 0; i < SNACK_COUNT; ++i) {
            cout << i + 1 << ". " << snacks[i].name << " - " << snacks[i].price << " руб.\n";
        }

        while (cin >> snackChoice && snackChoice != -1) {
            if (snackChoice > 0 && snackChoice <= SNACK_COUNT) {
                totalCost += snacks[snackChoice - 1].price;
            }
            else {
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }

        cout << "**Выберите напиток** (-1 для отмены):\n";
        for (int i = 0; i < DRINK_COUNT; ++i) {
            cout << i + 1 << ". " << drinks[i].name << " - " << drinks[i].price << " руб.\n";
        }

        while (cin >> drinkChoice && drinkChoice != -1) {
            if (drinkChoice > 0 && drinkChoice <= DRINK_COUNT) {
                totalCost += drinks[drinkChoice - 1].price;
                if (drinks[drinkChoice - 1].price >= DRINK_DISCOUNT_THRESHOLD) {
                    fancyDrinks++;
                    if (fancyDrinks > 4) {
                        totalCost -= drinks[drinkChoice - 1].price;
                    }
                }
            }
            else {
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }

        if (totalCost > ORDER_DISCOUNT_THRESHOLD) {
            totalCost *= 0.85;
        }

        cout << "**Итоговая сумма для оплаты: " << totalCost << " руб.**\n";

        system("pause");
        system("cls");
    }

    return 0;
}
