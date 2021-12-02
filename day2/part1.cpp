#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> n){

    for (int i = 0; i<n.size(); ++i){
        cout << n[i] << " ";
    }
}

void get_direction(string str, string *direction, int *ammount){
	int space = str.find(" ");
	*direction = str.substr(0, space);
	*ammount = stoi(str.substr(space, str.size()));
	return;
}

void solution(){
	ifstream file;
	file.open("input");
    string str;
    int x = 0;
    int y = 0;
    while(getline(file, str))
    {
    	string direction;
    	int ammount;
    	get_direction(str, &direction, &ammount);
    	if (direction == "up") {
    		x = x-ammount;
    	} else if (direction == "down") {
    		x = x+ammount;
    	} else if (direction == "forward"){
    		y = y+ammount;
    	} else {
    		cout << "error" << endl;
    	}

    }
    cout << x*y << endl;
	return;
}

int main(int argc, char const *argv[])
{
	//print_vector(values);
	solution();
	return 0;
}