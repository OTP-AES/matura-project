#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

char keygen()  // used to generate the key (in letters).
{
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    return alphabet[rand() % sizeof(alphabet)-1];
}

int convert_input(string user_input, int i)
{
    int converted_input_value = user_input[i]-'a';
    return converted_input_value;
}

int main()
{
    //get the users input and store it in a string
    cout << "enter message: ";
    string user_input;
    cin >> user_input;
    int repetitions = user_input.length();
    int converted_input[repetitions];
    cout << "input converted to numbers: " << endl;
    for (int i=0; i<repetitions;)
    {
        //utilize the function convert_input to convert the letters of the users input to their alphabetical position
        converted_input[i]=convert_input(user_input, i);
        cout << converted_input[i] << ", ";
        i++;
    }
    //generate the random key; same length as the message, values ranging from 0-25
    string key;
    srand(time(0)); //needs to be included to avoid constantly getting the same results
    cout << endl << "utilized key: " << endl;
    for (unsigned int i=0; i<repetitions;)
    {
        key += keygen();
        i++;
    }
    cout << key << endl;
    cout << "key converted to numbers: " << endl;
    int converted_key[repetitions];
    for (int i=0; i<repetitions;)
    {
        //again utilize the function convert_input to convert the letters of the key to numbers
        converted_key[i] = convert_input(key, i);
        cout << converted_key[i] << ", ";
        i++;
    }
    //perform addition of the key and message modulo 26
    int converted_ciphertext[repetitions];
    cout << endl << "modular addition of the message and key provide the ciphertext numbers: " << endl;
    for (int i=0; i<repetitions;)
    {
        converted_ciphertext[i] = (converted_key[i]+converted_input[i]) % 26;
        cout << converted_ciphertext[i] << ", ";
        i++;
    }
    //finally, the ciphertext numbers are converted into letters
    string ciphertext;
    cout << endl << "the ciphertext can now be obtained: " <<endl;
    for (unsigned int i=0; i<repetitions;)
    {
        ciphertext += converted_ciphertext[i]+'a';
        i++;
    }
    cout << ciphertext << endl;
    system("pause");
    return 0;
}
