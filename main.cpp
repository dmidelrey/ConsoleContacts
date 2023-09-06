#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& phone) {
        Contact contact = {name, phone};
        contacts.push_back(contact);
    }

    void viewContacts() {
        if (contacts.empty()) {
            std::cout << "Список контактов пуст." << std::endl;
            return;
        }

        std::cout << "Список контактов:" << std::endl;
        for (const auto& contact : contacts) {
            std::cout << "Имя: " << contact.name << ", Телефон: " << contact.phone << std::endl;
        }
    }

    void editContact(int index, const std::string& newName, const std::string& newPhone) {
        if (index >= 0 && index < contacts.size()) {
            contacts[index].name = newName;
            contacts[index].phone = newPhone;
        }
    }

    void deleteContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
        }
    }
};

int main() {
    ContactManager manager;

    while (true) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить контакт" << std::endl;
        std::cout << "2. Просмотреть контакты" << std::endl;
        std::cout << "3. Редактировать контакт" << std::endl;
        std::cout << "4. Удалить контакт" << std::endl;
        std::cout << "5. Выйти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string name, phone;
            std::cout << "Введите имя контакта: ";
            std::cin >> name;
            std::cout << "Введите номер телефона контакта: ";
            std::cin >> phone;
            manager.addContact(name, phone);
        } else if (choice == 2) {
            manager.viewContacts();
        } else if (choice == 3) {
            int index;
            std::string newName, newPhone;
            std::cout << "Введите индекс контакта, который хотите отредактировать: ";
            std::cin >> index;
            std::cout << "Введите новое имя контакта: ";
            std::cin >> newName;
            std::cout << "Введите новый номер телефона контакта: ";
            std::cin >> newPhone;
            manager.editContact(index, newName, newPhone);
        } else if (choice == 4) {
            int index;
            std::cout << "Введите индекс контакта, который хотите удалить: ";
            std::cin >> index;
            manager.deleteContact(index);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
