#include <bits/stdc++.h>

using namespace std;

string get_input(){
    ifstream file;
    file.open("input");
    string str;
    getline(file, str);
    return str;
}

vector<string> split(string input, const char *split_on){
    vector<string> splitted;
    string buffer;
    for (int i=0; i<input.size(); i++){
        if (input[i] == *split_on && !buffer.empty()){
            splitted.push_back(buffer);
            buffer.clear();
        } else {
            buffer.push_back(input[i]);
        }
    }
    if (!buffer.empty()){
        splitted.push_back(buffer);
    }
    return splitted;
}

vector<int> vstoi(vector<string> input){
    vector<int> output;
    for (int i=0; i<input.size(); i++){
        output.push_back(stoi(input[i]));
    }
    return output;
}

class fish {
    public:
        int timer = 0;
        bool tick();
};

bool fish::tick(){
    timer--;
    if (timer < 0){
        timer = 6;
        return true;
    } else {
        return false;
    }
}

vector<fish> parse_input(string input){
    fish glowfish;
    vector<fish> fishes;
    vector<int> int_input = vstoi(split(input, ","));
    for (int i=0; i<int_input.size(); i++){
        glowfish.timer = int_input[i];
        fishes.push_back(glowfish);
    }
    return fishes;
}

void solution(vector<fish> fishes){
    int n;
    fish glowfish;
    vector<fish> base(1, glowfish);
    glowfish.timer = 8;
    bool evalueted_all = true;
    while (evalueted_all){
        n = base.size();
        cout << i << "-iteration-" << n << endl;
        for (int j=0; j<n; j++){
            if (base[j].tick()) {
                base.push_back(glowfish);
            }
        }
    }
    cout << "Solution: " << base.size() << endl;
}

int main(int argc, char const *argv[])
{
	string input = get_input();
    vector<fish> fishes = parse_input(input);
	solution(fishes);
	return 0;
}