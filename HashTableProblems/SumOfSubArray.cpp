//Tiffany Abernathy Implementation of Finding a Continuous Subarray whoms sum is equal to a Given Value 

//Problem::Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
//In case of multiple subarrays, return the subarray which comes first on moving from left to right.

//Solution::Using a modified hash table insert the total sum as the key and the index as the value. Given that 0 <= i < j < n. Elements from i to j will form a subarray whoms sum is S
// if and only if Aj - Ai = S
//Therefore, if Aj - S exists within the Hash Table, get the value (index) and the sum of the A elements between the value and j = S. 

#include <iostream>
#include <vector>
using namespace std;

struct HashTableItem {
    int key, value;
    HashTableItem(long long key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashTable {
    const int TABLESIZE = 211;
    HashTableItem** hashTable;
    int goalSum;
    
    int hashFunction(long long totalSum) {
        return totalSum - goalSum;
    }

public:
    HashTable(long long goalSum) {
        hashTable = new HashTableItem * [TABLESIZE];
        for (int i = 0; i < TABLESIZE; i++) {
            hashTable[i] = NULL;
        }
        this->goalSum = goalSum;
    }
   
    void insert(long long totalSum, int value) {
        hashTable[totalSum] = new HashTableItem(totalSum, value);
    }
    int search(long long totalSum) {
        int hashKey = hashFunction(totalSum);

        if (hashKey < 0 || hashTable[hashKey] == NULL) {
            return -1;
        }
        else {
            HashTableItem* temp = hashTable[hashKey];
            return temp->value;
        }
    }
};

class SumOfSubArray {
public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        HashTable table = HashTable(s);
        table.insert(0, 0);
        int totalSum = 0;
        vector<int> values;
        for (int j = 0; j < n; j++) {
            totalSum += arr[j];
            int val = table.search(totalSum);
            if (val >= 0 && (j - val + 1 >= 1)) {
                values.push_back(val + 1);
                values.push_back(j + 1);
                return values;
            }
            table.insert(totalSum, j+1);
        }
        values.push_back(-1);
        return values;
    }
};

int main() {
    //int sum = 15;
    //int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //Output: 1 5

    //int sum = 12;
    //int arr[] = {1,2,3,7,5};
    //Output: 2 4

    //int sum = 8;
    //int arr[] = { 5, 3, 6, 2, 1, 3, 2};
    //Output: 1 2
    
    int sum = 20;
    int arr[] = { 1, 2, 3, 4, 5 };
    //Output: -1

    auto size = sizeof(arr) / sizeof(arr[0]);
    SumOfSubArray sumOfSubArray;
    vector<int> items = sumOfSubArray.subarraySum(arr, size, sum);
    for (int i = 0; i < items.size(); i++)
        cout << items[i] << " ";
    cout << endl;
}