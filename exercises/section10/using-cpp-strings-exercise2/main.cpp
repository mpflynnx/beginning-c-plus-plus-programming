#include <iostream>
#include <string>

int main()
{
                               //0123456789x12
    std::string journal_entry_1{ "Isaac Newton" };
    std::string journal_entry_2{ "Leibniz" };

    // erase first name Isaac
    journal_entry_1.erase(0, 6);

    // The journal entries should be sorted alphabetically based on the authors last name
    if (journal_entry_2 < journal_entry_1) {
        journal_entry_1.swap(journal_entry_2);
    }

    std::cout << journal_entry_1 << "\n" << journal_entry_2; // Leibniz '\n' Newton

    return 0;
}

