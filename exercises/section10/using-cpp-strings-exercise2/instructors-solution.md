```c
    journal_entry_1.erase(0, 6);
    
    if (journal_entry_2 < journal_entry_1) 
        journal_entry_2.swap(journal_entry_1);
        
    /*THE FOLLOWING WILL ALSO WORK
    if (journal_entry_1 > journal_entry_2)
        journal_entry_1.swap(journal_entry_2);
    */
```