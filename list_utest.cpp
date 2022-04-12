#include "gtest/gtest.h"
#include "List.h"
#include <iostream>

struct ListFixture : public ::testing::Test {
    const size_t size = 10;
    List<int> testList;

    void SetUp() override {
        testList.add(10);
        testList.add(15);
        testList.add(20);
    }

    void TearDown() override {

    }
};

TEST_F(ListFixture, AddGetTest) {
    ASSERT_EQ(testList.get(0), 10);
    ASSERT_EQ(testList.get(1), 15);
    ASSERT_EQ(testList.get(2), 20);

    ASSERT_THROW(testList.get(3), std::out_of_range);
}

TEST_F(ListFixture, DelTest) {
    testList.del(1);
    ASSERT_EQ(testList.get(0), 10);
    ASSERT_EQ(testList.get(1), 20);

    testList.del(1);
    ASSERT_EQ(testList.get(0), 10);

    ASSERT_THROW(testList.del(1), std::out_of_range);
}

TEST_F(ListFixture, InsertTest) {
    testList.insert(13, 1);
    testList.insert(25, 4);

    ASSERT_EQ(testList.get(1), 13);
    ASSERT_EQ(testList.get(4), 25);

    ASSERT_THROW(testList.insert(100, 6), std::out_of_range);
}

TEST_F(ListFixture, IteratorTest) {
    ASSERT_THROW(Iterator<int> emptyIt {nullptr}, std::out_of_range);

    Iterator<int> it {testList.firstIterator()};
    ASSERT_EQ(it.get(), testList.get(0));
    for(size_t i {1}; it.hasNext(); i++) {
        it.next();
        ASSERT_EQ(it.get(), testList.get(i));
    }

    ASSERT_THROW(it.next(), std::out_of_range);
}