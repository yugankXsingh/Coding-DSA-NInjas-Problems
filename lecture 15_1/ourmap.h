#include <iostream>
using namespace std;
#include <string>

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode<V> *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

/*****************************************************************************************************************/

template <typename V>
class ourmap
{
    MapNode<V> **buckets; // array which stores head pointer of linked list
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

private:
    int getbucketIndex(string key)
    {
        int hashcode = 0;
        int currentCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentCoeff;
            hashcode = hashcode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashcode % numBuckets;
    }

    /*****************************************************************************************************************/

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];

        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }

        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];

            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;

                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }

        delete[] temp;
    }

    /*****************************************************************************************************************/

public:
    double getloadFactor()
    {
        return (1.0 * count) / numBuckets;
    }
    /*****************************************************************************************************************/

    void insert(string key, V value)
    {
        int bucketIndex = getbucketIndex(key);

        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];

        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.0 * count) / numBuckets;

        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    /*****************************************************************************************************************/

    V remove(string key)
    {
        int bucketIndex = getbucketIndex(key);

        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev != NULL)
                {
                    prev->next = head->next;
                }
                else
                {
                    buckets[bucketIndex] = head->next;
                }
                V ans = head->value;
                delete head;
                count--;
                return ans;
            }
            prev = head;
            head->next = NULL;
        }

        return 0;
    }

    /*****************************************************************************************************************/

    V getValue(string key)
    {
        int bucketIndex = getbucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    int size()
    {
        return count;
    }
};