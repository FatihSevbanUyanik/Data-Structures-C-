/**
* Title : main
* Author :Fatih Sevban Uyanık
* ID: 21602485
* Section : 1
* Assignment : 4
* Description : Illustrates the hash tables
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "OpenHashTable.h"
#include "FileReader.h"
#include "ChainHashTable.h"
using namespace std;

int main() {

    // ==============================================
    // Reading items.txt
    // ==============================================

    int fruitCount = 0;
    string *fruits;
    int *fruitCounts;

    FileReader fileReader;
    fileReader.readTextFile(fruitCount, fruits, fruitCounts);

    // ==============================================
    // Constructing Open Address Hash Table
    // ==============================================

    cout << endl;
    cout << "==============================================================" << endl;
    cout << "===================OPEN ADRESS HASH TABLE=====================" << endl;
    cout << "==============================================================" << endl;
    cout << endl;

    int OPEN_TABLE_SIZE = 161;
    OpenHashTable openHashTable(OPEN_TABLE_SIZE);
    for (int i = 0; i < fruitCount; i++) {
        double collisionCount = 0;
        openHashTable.insertItem(fruits[i], fruitCounts[i], collisionCount);
    }

    // ==============================================
    // Printing Open Address Hash Table
    // ==============================================

    openHashTable.printTable();

    // ==============================================
    // Retrieving three favourite fruits.
    // ==============================================

    string str1 = "grapes green";     // 11
    string str2 = "lemons yellow";    // 14
    string str3 = "orange navel";     // 24

    double comp1 = 0;
    OpenEntry entry1 = openHashTable.retrieveItem(str1, comp1);
    double comp2 = 0;
    OpenEntry entry2 = openHashTable.retrieveItem(str2, comp2);
    double comp3 = 0;
    OpenEntry entry3 = openHashTable.retrieveItem(str3, comp3);
    entry1.printEntry();
    entry2.printEntry();
    entry3.printEntry();

    // ==============================================
    // Deleting three least vegetables
    // ==============================================

    str1 = "cucumber";
    str2 = "jicama";
    str3 = "guajes";

    openHashTable.deleteItem(str1);
    openHashTable.deleteItem(str2);
    openHashTable.deleteItem(str3);

    // ==============================================
    // Print the hash table
    // ==============================================

    openHashTable.printTable();


    // ==============================================
    // Constructing Chain Hash Table
    // ==============================================

    cout << endl;
    cout << "==============================================================" << endl;
    cout << "======================CHAIN HASH TABLE========================" << endl;
    cout << "==============================================================" << endl;
    cout << endl;

    ChainHashTable chainHashTable(47);
    for (int i = 0; i < fruitCount; i++) {
        chainHashTable.insertItem(fruits[i], fruitCounts[i]);
    }

    // ==============================================
    // Printing Open Address Hash Table
    // ==============================================

    chainHashTable.printTable();

    // ==============================================
    // Retrieving three favourite fruits.
    // ==============================================

    str1 = "grapes green";
    str2 = "lemons yellow";
    str3 = "orange navel";
    double comparisonCount1 = 0;
    double comparisonCount2 = 0;
    double comparisonCount3 = 0;
    ChainEntry chainEntry1 = chainHashTable.retrieveItem(str1, comparisonCount1);
    ChainEntry chainEntry2 = chainHashTable.retrieveItem(str2, comparisonCount2);
    ChainEntry chainEntry3 = chainHashTable.retrieveItem(str3, comparisonCount3);
    chainEntry1.printEntry();
    chainEntry2.printEntry();
    chainEntry3.printEntry();


    // ==============================================
    // Deleting three least vegetables
    // ==============================================

    str1 = "cucumber";
    str2 = "jicama";
    str3 = "guajes";

    chainHashTable.deleteItem(str1);
    chainHashTable.deleteItem(str2);
    chainHashTable.deleteItem(str3);

    // ==============================================
    // Print the hash table
    // ==============================================

    chainHashTable.printTable();
    cout << endl;
    cout << endl;

    // ==============================================
    // Analysis of Open Addressing
    // ==============================================

    // calculating average insertion
    double averageInsertionDuration = 0;
    double averageCollisions = 0;

    for (int j = 0; j < 10000; j++) {
        clock_t startTime = clock();
        OpenHashTable hashTable(OPEN_TABLE_SIZE);
        for (int i = 0; i < fruitCount; i++) {
            double collision = 0;
            hashTable.insertItem(fruits[i], fruitCounts[i], collision);
            averageCollisions += collision;
        }
        averageInsertionDuration += 1000 * double( clock() -
                startTime ) / CLOCKS_PER_SEC;
    }

    averageInsertionDuration = (averageInsertionDuration / 10000) / fruitCount;
    averageCollisions = (averageCollisions / 10000) / fruitCount;

    // calculating average retrieval
    OpenHashTable hashTable(OPEN_TABLE_SIZE);
    for (int i = 0; i < fruitCount; i++) {
        double collisionCount = 0;
        hashTable.insertItem(fruits[i], fruitCounts[i], collisionCount);
    }

    double averageRetrievalDuration = 0;
    double averageComparison = 0;
    for (int j = 0; j < 10000; j++) {
        clock_t startTime = clock();
        for (int i = 0; i < 100; i++) {
            int randomIndex = rand() % fruitCount;
            double comparisonCount = 0;
            OpenEntry entry = hashTable.retrieveItem(fruits[randomIndex], comparisonCount);
            averageComparison += comparisonCount;
        }
        averageRetrievalDuration += 1000 * double( clock() -
                startTime ) / CLOCKS_PER_SEC;
    }

    averageRetrievalDuration = (averageRetrievalDuration / 10000) / 100;
    averageComparison = (averageComparison / 10000) / 100;

    // calculating average deletion
    double averageDeletionDuration = 0;
    for (int j = 0; j < 10000; j++) {
        OpenHashTable hashTableSample(OPEN_TABLE_SIZE);
        for (int i = 0; i < fruitCount; i++) {
            double collisionCount = 0;
            hashTableSample.insertItem(fruits[i], fruitCounts[i], collisionCount);
        }
        clock_t startTime = clock();
        hashTableSample.deleteRandom(100);
        averageDeletionDuration += 1000 * double(clock() -
                startTime ) / CLOCKS_PER_SEC;
    }

    averageDeletionDuration = (averageDeletionDuration / 10000) / 100;

    cout << "-------------------------------------------------------" << endl;
    cout << "Part a - Analysis of Open Addressing Hash Table" << endl;
    cout << "Parameter                   Time Elapsed" << endl;
    cout << "Average Insertion Time      " << averageInsertionDuration << " ms" << endl;
    cout << "Average Retrieval Time      " << averageRetrievalDuration << " ms" << endl;
    cout << "Average Deletion  Time      " << averageDeletionDuration  << " ms" << endl;
    cout << endl;
    cout << "Number of comparisons in Retrieval = " << averageComparison << endl;
    cout << "Number of collisions  in Insertion = " << averageCollisions << endl;
    cout << "-------------------------------------------------------" << endl;

    // ==============================================
    // Analysis of Chain Addressing
    // ==============================================

    int CHAIN_TABLE_SIZE = 47;

    // calculating average insertion
    averageInsertionDuration = 0;
    for (int j = 0; j < 10000; j++) {
        clock_t startTime = clock();
        ChainHashTable hashTableSample(CHAIN_TABLE_SIZE);
        for (int i = 0; i < fruitCount; i++) {
            hashTableSample.insertItem(fruits[i], fruitCounts[i]);
        }
        averageInsertionDuration += 1000 * double( clock() -
                startTime ) / CLOCKS_PER_SEC;
    }
    averageInsertionDuration = (averageInsertionDuration / 10000) / fruitCount;

    // calculating average retrieval
    ChainHashTable hashTable2(CHAIN_TABLE_SIZE);
    for (int i = 0; i < fruitCount; i++) {
        hashTable2.insertItem(fruits[i], fruitCounts[i]);
    }

    averageRetrievalDuration = 0;
    averageComparison = 0;
    for (int j = 0; j < 10000; j++) {
        clock_t startTime = clock();
        for (int i = 0; i < 100; i++) {
            int randomIndex = rand() % fruitCount;
            double comparisonCount = 0;
            ChainEntry entry = hashTable2.retrieveItem(fruits[randomIndex], comparisonCount);
            averageComparison += comparisonCount;
        }
        averageRetrievalDuration += 1000 * double( clock() -
                startTime ) / CLOCKS_PER_SEC;
    }

    averageRetrievalDuration = (averageRetrievalDuration / 10000) / 100;
    averageComparison = (averageComparison / 10000) / 100;

    // calculating average deletion
    averageDeletionDuration = 0;
    for (int j = 0; j < 10000; j++) {
        ChainHashTable hashTableSample(CHAIN_TABLE_SIZE);
        for (int i = 0; i < fruitCount; i++) {
            hashTableSample.insertItem(fruits[i], fruitCounts[i]);
        }
        clock_t startTime = clock();
        hashTableSample.deleteRandom(100);
        averageDeletionDuration += 1000 * double(clock() -
                startTime ) / CLOCKS_PER_SEC;
    }
    averageDeletionDuration = (averageDeletionDuration / 10000) / 100;

    cout << "-------------------------------------------------------" << endl;
    cout << "Part b -  Analysis of Separate Chain Hash Table" << endl;
    cout << "Parameter                   Time Elapsed" << endl;
    cout << "Average Insertion Time      " << averageInsertionDuration << endl;
    cout << "Average Retrieval Time      " << averageRetrievalDuration << endl;
    cout << "Average Deletion  Time      " << averageDeletionDuration  << endl;
    cout << endl;
    cout << "Number of comparisons in Retrieval = " << averageComparison  << " ms" << endl;
    cout << "-------------------------------------------------------" << endl;

    delete [] fruits;
    delete [] fruitCounts;
    return 0;
}