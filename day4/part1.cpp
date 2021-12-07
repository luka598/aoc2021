#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> n){
    cout << "vector: ";
    for (int i = 0; i<n.size(); ++i){
        cout << n[i] << " ";
    }
    cout << endl;
}

void print_s_vector(vector<string> n){
    cout << "vector: ";
    for (int i = 0; i<n.size(); ++i){
        cout << n[i] << " ";
    }
    cout << endl;
}

vector<string> get_input(){
	ifstream file;
	file.open("input");
    string str;
    vector<string> input;
    while(getline(file, str))
    {
    	input.push_back(str);
    }
	return input;
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

vector<int> get_drawn(vector<string> input){
	vector<int> drawn = vstoi(split(input[0], ","));
	return drawn;
}

class bingo {
	public:
		int matrix[5][5];
		vector<vector<int>> values();
		bool check(vector<int> drawn);
		void add_row(vector<int> values);
		int score(vector<int> drawn);
	private:
		int row = 0;
};

vector<vector<int>> bingo::values(){
	vector<int> row(5);
	vector<int> column(5);
	vector<vector<int>> values;
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			row[j] = matrix[i][j];
			column[j] = matrix[j][i];
		}
		values.push_back(row);
		values.push_back(column);
	}
	return values;
}

void bingo::add_row(vector<int> values){
	if (row > 4)
		cout << "Warning row > 4" << endl;
	copy(values.begin(), values.end(), matrix[row]);
	row++;
}

bool bingo::check(vector<int> drawn){
	vector<vector<int>> values = bingo::values();
	int matched;
	for (int i=0; i<values.size(); i++){
		matched = 0;
		for (int j=0; j<values[i].size(); j++){
			if (find(drawn.begin(), drawn.end(), values[i][j]) != drawn.end()){
				matched = matched + 1;
			}
		}
		if (matched == 5){
			return true;
		}
	}
	return false;
}

int bingo::score(vector<int> drawn){
	int sum = 0;
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			if (find(drawn.begin(), drawn.end(), matrix[i][j]) == drawn.end()){
				sum = sum + matrix[i][j];
			}
		}
	}
	return sum * drawn.back();
}

vector<bingo> get_bingos(vector<string> input){
	input.erase(input.begin());
	bingo b;
	vector<bingo> bingos;
	for (int i=0; i<input.size(); i++){
		if (i%6 == 0){
			bingos.push_back(b);
		} else {
			bingos.back().add_row(vstoi(split(input[i], " ")));
		}
	}
	return bingos;
}

void solution(vector<int> all_drawn, vector<bingo> bingos){
	vector<int> drawn;
	for (int i=0; i<all_drawn.size(); i++){
		drawn.push_back(all_drawn[i]);
		for (int j=0; j<bingos.size(); j++){
			if (bingos[j].check(drawn)) {
				printf("Found bingo on %d,%d\n", i, j);
				printf("Solution: %d", bingos[j].score(drawn));
				return;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<string> input = get_input();
	vector<int> drawn = get_drawn(input);
	vector<bingo> bingos = get_bingos(input);

	solution(drawn, bingos);
	return 0;
}