#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Person.hpp"
#include "Date.hpp"
#include "Member.hpp"
#include "Book.hpp"
#include "Librarian.hpp"
#include <sstream>

using namespace std;
TEST_CASE("Reading CSV File")
{
    map<int, Book> books;
    REQUIRE(readBooksFromCSV(books) == "File successfully read library_books.csv");
}

TEST_CASE("Creating New Member")
{
    Member member(1, "TestingName", "TestingAddress", "TestingEmail");
    REQUIRE(member.ShowDetail() == "Name: TestingName\nAddress: TestingAddress\nEmail: TestingEmail\n");
}

TEST_CASE("Issueing Book") {
    Member member(1, "TestingName", "TestingAddress", "TestingEmail");
    
    Librarian librarian;
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    member.setBooksBorrowed(1);
    std::cout.rdbuf(oldCout);
    REQUIRE(output.str() == "Book ID:1 issued to member ID: 1\n");
}