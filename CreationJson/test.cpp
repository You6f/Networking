#include <cstdio>

int main()
{
    // Specify the file path
    const char *filename = "test.json";

    // Attempt to delete the file
    if (std::remove(filename) != 0)
    {
        perror("Error deleting file");
    }
    else
    {
        printf("File deleted successfully\n");
    }

    return 0;
}
