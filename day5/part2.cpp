#include <bits/stdc++.h>

using namespace std;

void print_i_vector(vector<int> n){
    for (int i = 0; i<n.size(); ++i){
        cout << n[i] << " ";
    }
    cout << endl;
}

void print_s_vector(vector<string> n){
	cout << "[";
    for (int i = 0; i<n.size(); ++i){
        cout << "\"" << n[i] << "\"" << ", ";
    }
    cout << "]" << endl;
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

void print2d(vector<vector<int>> matrix){
	for (int x=0; x < matrix.size(); x++){
		for (int y=0; y < matrix[x].size(); y++){
			if (matrix[x][y]==0){
				cout << ".";
			} else {
				cout << matrix[x][y];
			}
		}
		cout << endl;
	}
}

vector<tuple<int,int,int,int>> get_points(vector<string> input){
	tuple<int,int,int,int> line;// x0, y0, x1, y1
	vector<tuple<int,int,int,int>> points;
	vector<string> temp;
	vector<int> xy0;
	vector<int> xy1;
	for (int i=0; i<input.size(); i++){
		temp = split(input[i], " ");
		xy0 = vstoi(split(temp[0], ","));
		get<0>(line) = xy0[0];
		get<1>(line) = xy0[1];
		xy1 = vstoi(split(temp[2], ","));
		get<2>(line) = xy1[0];
		get<3>(line) = xy1[1];
		points.push_back(line);
	}
	return points;
}

int solution(vector<tuple<int,int,int,int>> points){
	vector<vector<int>> field(1000, vector<int>(1000, 0));
	int overlap = 0;
	int x0, x1, y0, y1;
	int x, y, lx, ly, sx, sy;
	
	for (int i=0; i<points.size(); i++){
		tie(x0,y0,x1,y1) = points[i];
		lx = abs(x1-x0);
		ly = abs(y1-y0);
		if (x1-x0==0){sx=0;} else {sx=(x1-x0)>0 ? 1 : -1;}
		if (y1-y0==0){sy=0;} else {sy=(y1-y0)>0 ? 1 : -1;}		
		for (int j=0; j<=max(lx, ly); j++){
				x = x0 + sx * j;
				y = y0 + sy * j;
				field[y][x] = field[y][x] + 1;
		}
	}
	
	print2d(field);
	for (int x=0; x<1000; x++){
		for (int y=0; y<1000; y++){
			if (field[y][x] >= 2){
				overlap++;
			}
		}
	}
	cout << "Solution: " << overlap << endl;
	return 0;
}

int main(int argc, char const *argv[])
{
	vector<string> input = get_input();
	vector<tuple<int,int,int,int>> points = get_points(input);
	int x = solution(points);
	return 0;
}