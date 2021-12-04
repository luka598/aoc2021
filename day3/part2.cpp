#include <bits/stdc++.h>

using namespace std;

void print_list(list<string> values){
	for (list<string> :: iterator i=values.begin(); i!=values.end(); i++){
		cout << *i << endl;
	}
}

void print_vector(vector<int> n){

    for (int i = 0; i<n.size(); ++i){
        cout << n[i] << " ";
    }
    cout << endl;
}

string bin_v_s(vector<int> bin, bool invert = false){
	for (int i=0; i<bin.size(); i++){
		if (invert)
			bin[i] = abs(bin[i]-1);
		bin[i] = bin[i]+48;
	}
	string bin_s(bin.begin(), bin.end());
	return bin_s;
}

vector<int> avg_bits(int bin_len, list<string> values, bool round_up){
	vector<int> binary (bin_len);
	list<string> :: iterator it = values.begin();
	int i=0;
	while (it != values.end()){
    	for (int j=0; j<bin_len; j++){
    		binary[j] = binary[j] + (*it)[j] - 48;
    	}
    	i++;
    	it++;
    }
    for (int i=0; i<bin_len; i++){
    	binary[i] = round(binary[i]/(float)values.size());
    	if (!round_up)
    		binary[i] = abs(binary[i]-1);
    }
    return binary;
}

int search(int bin_len, list<string> values, bool round_up){
	vector<int> binary;
	string bin_s;
	int bit = 0;
	while (values.size() > 1){
		binary = avg_bits(bin_len, values, round_up);
		bin_s = bin_v_s(binary);
		auto condition = [bin_s, bit](string s){
			if (bin_s[bit] != s[bit]){
				return true;
			} else {
				return false;
			}
		};
		auto it = remove_if(values.begin(), values.end(), condition);
		values.erase(it, values.end());
		bit++;
	}
	int decimal = 0;
	string result = values.front();
	for (int i=0; i<bin_len; i++){
		decimal = decimal + (result[bin_len-i-1]-48) * pow(2, i);
	}
	return decimal;
}

void solution(){
	ifstream file;
	file.open("input");
    string str;
    int bin_len = 12;
    list<string> values;
    while(getline(file, str)){
    	values.push_back(str);
    }
    int oxygen = search(bin_len, values, true);
    int co2 = search(bin_len, values, false);
    cout << "Solution: " << oxygen*co2 << endl;
	return;
}

int main(int argc, char const *argv[])
{
	solution();
	return 0;
}