/*
  Reference: http://www.algolist.net/Data_structures/Hash_table/Chaining
*/
class HashEntry
{
private:
    int key;
    int value;
    HashEntry *next;
public:
    HashEntry(int key, int value)
	{
	    this->key = key;
	    this->value = value;
	    this->next = NULL;
	}
    int getKey()
	{
	    return key;
	}
    int getValue()
	{
	    return value;
	}
    void setValue(int value)
	{
	    this->value = value;
	}
    HashEntry *getNext()
	{
	    return next;
	}
    void setNext(HashEntry *next)
	{
	    this->next = next;
	}
};

const int TABLE_SIZE = 128;

class HashMap
{
private:
    HashEntry **table;
public:
    HashMap()
	{
	    table = new HashEntry*[TABLE_SIZE];
	    for(int i = 0; i < TABLE_SIZE; ++i)
		table[i] = NULL;
	}
    int get(int key)
	{
	    int hash = (key % TABLE_SIZE);
	    if(table[hash] == NULL)
		return -1;
	    else
	    {
		HashEntry *entry = table[hash];
		while(entry != NULL && entry->getKey() != key)
		    entry = entry->getNext();
		if(entry == NULL)
		    return -1;
		else
		    return entry->getValue();
	    }
	}
    void put(int key, int value)
    {
    	int hash = (key % TABLE_SIZE);
    	if(table[hash] == NULL)
    	    table[hash] = new HashEntry(key, value);
    	else
    	{
    	    HashEntry *entry = table[hash];
            while (entry->getNext() != NULL)
                entry = entry->getNext();
            if (entry->getKey() == key)
                entry->setValue(value);
             else
                entry->setNext(new HashEntry(key, value));
    	}
    }
    void remove(int key)
	{
	    int hash = (key % TABLE_ZIZE);
	    if(table[hash] != NULL)
	    {
		HashEntry *prev = NULL;
		HahsEntry *entry = table[hash];
		while(entry->getNext() != NULL && entry->getKey() != key)
		{
		    prev = entry;
		    entry = entry->getNext();
		}
		if(entry->getKey() == key)
		{
		    if(prev == NULL)
		    {
			HashEntry *nextEntry = entry->getNext();
			delete entry;
			table[hash] = nextEntry;
		    }
		    else
		    {
			HashEntry *next = entry->getNext();
			delete entry;
			prev->setNext(next);
		    }
		}
	    }
	}
    ~HashMap()
	{
	    for(int i = 0; i < TABLE_SIZE; ++i)
	    {
		if(table[i] != NULL)
		{
		    HashEntry *prev = NULL;
		    HashEntry * entry = table[i];
		    while(entry != NULL)
		    {
			prev = entry;
			entry = entry->getNext();
			delete prev;
		    }
		}
		delete [] table;
	    }
	}
};
