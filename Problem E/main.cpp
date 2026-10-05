#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;
array<array<int, 7>, 10> validSegments = {};
array<int, 7> segmentDecoding(string input[7]){
    array<int, 7> result = {};
    // ai was used to write out the representations
    if (input[0][1] == '#') result[0] = 1;
    if (input[1][0] == '#') result[1] = 1;
    if (input[1][3] == '#') result[2] = 1;
    if (input[3][1] == '#') result[3] = 1;
    if (input[4][0] == '#') result[4] = 1;
    if (input[4][3] == '#') result[5] = 1;
    if (input[6][1] == '#') result[6] = 1;
    return result;

}
int main(){
    // ai was used to write out the representations
    validSegments[0] = {1, 1, 1, 0, 1, 1, 1};
    validSegments[1] = {0, 0, 1, 0, 0, 1, 0};
    validSegments[2] = {1, 0, 1, 1, 1, 0, 1};
    validSegments[3] = {1, 0, 1, 1, 0, 1, 1};
    validSegments[4] = {0, 1, 1, 1, 0, 1, 0};
    validSegments[5] = {1, 1, 0, 1, 0, 1, 1};
    validSegments[6] = {1, 1, 0, 1, 1, 1, 1};
    validSegments[7] = {1, 0, 1, 0, 0, 1, 0};
    validSegments[8] = {1, 1, 1, 1, 1, 1, 1};
    validSegments[9] = {1, 1, 1, 1, 0, 1, 1};
    string input[7];
    array<int, 7> segments = {};
    for (int i = 0; i < 7; i++){
        cin >> input[i];
    }
    segments = segmentDecoding(input);
    vector<int> valid;
    //AI was used to find a fatal bug where
    //only up to 98 would be checked
    for (int i = 0; i <= 99; i++){
        array<int, 7> mask = {};
        if (i < 10){
            //AI was used to find an unnecessary check
            //since we are checking for valid segments later
            mask = validSegments[i];
        }
        else{
            int firstDigit = i/10;
            int secondDigit = i%10;
            for (int j = 0; j < 7; j++){
                mask[j] = validSegments[firstDigit][j] ^ validSegments[secondDigit][j];
            }
        }
        if (mask == segments){
            valid.push_back(i);
        }

    }
    if (valid.size() == 0){
        cout << "impossible";
    }
    for (int i = 0; i < valid.size(); i++){
        //AI was used to find a big
        //where after the last number is printed a space is printed
        cout << valid[i] << (i+1 == valid.size() ? "" : " ");
    }
    return 0;
}