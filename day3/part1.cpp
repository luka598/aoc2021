#include <bits/stdc++.h>

using namespace std;

void solution(){
	ifstream file;
	file.open("input");
    string str;
    int bin_len = 12;
    float binary[bin_len] = {0};
    while(getline(file, str)){
    	for (int i=0; i<bin_len; i++){
    		binary[i] = binary[i] + str[i] - 48;
    	}
    }
    int gamma = 0;
    int epsilon = 0;
    for (int i=0; i<bin_len; i++){
    	gamma = gamma + round(binary[i]/1000)*pow(2, i);
    }
    epsilon = pow(2, bin_len) - gamma - 1;
    cout << "Solution: " << gamma*epsilon << endl;
	return;
}

int main(int argc, char const *argv[])
{
	//print_vector(values);
	solution();
	return 0;
}