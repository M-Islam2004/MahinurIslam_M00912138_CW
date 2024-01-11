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

Librarian librarian;
TEST_CASE("Reading CSV File")
{
    REQUIRE(librarian.readBooksFromCSV(books) == "File successfully read library_books.csv");
}

TEST_CASE("Creating New Member")
{
    Member member(1, "TestingName1", "TestingAddress1", "TestingEmail1");
    members[1] = member;
    REQUIRE(member.ShowDetail() == "Name: TestingName1\nAddress: TestingAddress1\nEmail: TestingEmail1\n");

    Member member2(2, "TestingName2", "TestingAddress2", "TestingEmail2");
    members[2] = member2;
    REQUIRE(member2.ShowDetail() == "Name: TestingName2\nAddress: TestingAddress2\nEmail: TestingEmail2\n");

}

TEST_CASE("Issueing Book") {
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    members[1].setBooksBorrowed(1);
    members[1].setBooksBorrowed(2);
    std::cout.rdbuf(oldCout);
    REQUIRE(output.str() == "Book ID:1 issued to member ID: 1\nBook ID:2 issued to member ID: 1\n");
}

TEST_CASE("List Books") {
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    librarian.listBooksBorrowed(1);
    std::cout.rdbuf(oldCout);
    REQUIRE(output.str() == "1: A Daughter of the Snows\n2: \"The Near East: 10\n\n");
}

TEST_CASE("Salary") {
    librarian.SetSalary(20000);
    REQUIRE(librarian.GetSalary() == 20000);
}

TEST_CASE("StaffID") {
    librarian.SetStaffID(1);
    REQUIRE(librarian.GetStaffID() == 1);
}