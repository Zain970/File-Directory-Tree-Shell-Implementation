#include "pch.h"
#include "../../Answer/19I-0538_C_A3.h" 
#include <fstream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////// Test -1 /////////////////////////////////////////////////////////////////
TEST(testNTreeCreation, InputFileReadingTest)                     
{
    string inputFilePath = "input.txt";
    string outputFilePath = "levelOrder.txt";      // file must be created in solution folder
    string expectedFilePath = "LevelOrderOutput.txt";

    createTree(inputFilePath);
    levelOrderFunction(outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }
            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -2 /////////////////////////////////////////////////////////////////

TEST(insertFile, insertFileTest)
{

    string inputFilePath = "input.txt";
    string outputFilePath = "InsertFile.txt";       // file must be created in solution folder
    string expectedFilePath = "InsertFileOutput.txt";
    string source = "testcase.txt";
    string targetPath = "/root/bin/apt-get";

    createTree(inputFilePath);
    insertFileFolder(source, targetPath, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);


    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -3 /////////////////////////////////////////////////////////////////

TEST(insertFolder, insertFolderTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "InsertFolder.txt"; // file must be created in solution folder
    string expectedFilePath = "InsertFolderOutput.txt";
    string source = "testcase";
    string targetPath = "/usr/dev";

    createTree(inputFilePath);
    insertFileFolder(source, targetPath, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -4 /////////////////////////////////////////////////////////////////

TEST(insertFolderFail, insertFolderFailTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "FailTest.txt"; // file must be created in solution folder
    string expectedFilePath = "LevelOrderOutput.txt";
    string source = "testcase";
    string targetPath = "/usr/dev/echo.txt";

    createTree(inputFilePath);
    insertFileFolder(source, targetPath, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -5 /////////////////////////////////////////////////////////////////

TEST(deleteFile, deleteFileTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "DeleteFile.txt";                // file must be created in solution folder
    string expectedFilePath = "DeleteFileOutput.txt";
    string targetPath = "/root/bin/ls.cpp";

    createTree(inputFilePath);
    deleteFileFolder(targetPath, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -6 /////////////////////////////////////////////////////////////////

TEST(deleteFolder, deleteFolderTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "DeleteFolder.txt";                      // file must be created in solution folder
    string expectedFilePath = "DeleteFolderOutput.txt";
    string targetPath = "/home/Desktop/Assignments";

    createTree(inputFilePath);
    deleteFileFolder(targetPath, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -7 ///////////////////////////////////////////////////////////////////////////////////

TEST(mergeFolder, mergeFolderTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "MergeFolder.txt"; // file must be created in solution folder
    string expectedFilePath = "MergeFolderOutput.txt";
    string sourcePath = "/home/Desktop/Assignments";
    string targetPath = "/root/bin/apt-get";

    createTree(inputFilePath);
    mergeFolder(sourcePath, targetPath, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -8 /////////////////////////////////////////////////////////////////

TEST(searchFile, searchFileTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "SearchFile.txt"; // file must be created in solution folder
    string expectedFilePath = "SearchFileOutput.txt";
    string targetFile = "Test.cpp";

    createTree(inputFilePath);
    searchFileFolder(targetFile, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}

///////////////////////////////////////////////////////// Test -9 /////////////////////////////////////////////////////////////////

TEST(searchFolder, searchFolderTest)
{ 

    string inputFilePath = "input.txt";
    string outputFilePath = "SearchFolder.txt";  // file must be created in solution folder
    string expectedFilePath = "SearchFolderOutput.txt";
    string targetFolder = "lib";

    createTree(inputFilePath);
    searchFileFolder(targetFolder, outputFilePath);

    ifstream outputFile(outputFilePath);
    ifstream expectedFile(expectedFilePath);
    if (!outputFile.is_open() || !expectedFile.is_open())
    {
        if (!outputFile.is_open())
        {
            cout << outputFilePath << " File Not Found" << endl;
        }
        if (!expectedFile.is_open())
        {
            cout << expectedFilePath << " File Not Found" << endl;
        }
        ASSERT_TRUE(false);
    }
    else
    {
        string org, res;
        while (1)
        {
            if (expectedFile.eof() && outputFile.eof())
            {
                break;
            }
            if (expectedFile.eof())
            {
                org = "";
            }
            else
            {
                expectedFile >> org;
            }

            if (outputFile.eof())
            {
                res = "";
            }
            else
            {
                outputFile >> res;
            }

            EXPECT_EQ(org, res);
        }
    }
    outputFile.close();
    expectedFile.close();
}