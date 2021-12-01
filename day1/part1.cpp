#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> n){

    for (int i = 0; i<n.size(); ++i){
        cout << n[i] << " ";
    }
}

vector<int> load_values(){
	ifstream file;
	file.open("input");
    vector<int> values;
    string str;
    while(getline(file, str))
    {
    	values.push_back(stoi(str));
    }
	return values;
}

void solution(vector<int> values){
	int larger = 0;
	for (int i=0; i<values.size(); i++){
		if (i > 0){
			if (values[i] > values[i-1]) {
				larger++;
			}
		}
	}
	cout << larger << endl;
	return;
}

int main(int argc, char const *argv[])
{
	vector<int> values = load_values();
	//print_vector(values);
	solution(values);
	return 0;
}