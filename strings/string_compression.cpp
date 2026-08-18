#include<iostream>
#include<vector>
#include<string>
using namespace std;


int compress(vector<char> &chars){
    if(chars.size() <= 1) return chars.size();

    int count = 1, w = 0;
    for(int i = 0; i < chars.size(); i++){
        if((i < chars.size() - 1) && (chars[i] == chars[i+1])){
            count ++;
        }

        else if(count > 1){
            chars[w] = chars[i]; // this time its still pointing to the same character
            w++;
            string cnt_str = to_string(count);
            for(int i = 0; i < cnt_str.length(); i++){
                chars[w] = cnt_str[i];
                w++;
            }
            count = 1;
        }
        else{
            chars[w] = chars[i];
            w++;
            count = 1;
        }

    }

    return w ;

}
void print_vector(vector<char> chars, int size){
    for(int i = 0; i < size; i++){
        cout << chars[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<char> chars = {'a','a','a','b','b','c'};
    int size = compress(chars);
    cout << size << endl;
    print_vector(chars,size);

    return 0;
}