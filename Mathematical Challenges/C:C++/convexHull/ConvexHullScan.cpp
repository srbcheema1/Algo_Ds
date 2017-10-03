#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

//This function decides if 3 points form a right turn or not
bool Is_Right_Turn(vector <pair<int,int>> Hull){
	pair <int,int> P1, P2, P3;
	int Determinant;

	//P1, P2 and P3 are the last 3 points in the given Hull
	P1 = Hull[Hull.size() - 3];
	P2 = Hull[Hull.size() - 2];
	P3 = Hull[Hull.size() - 1];

	/*Cross Product is given by the determinant of the following 3x3 matrix - 
	1    P1.x    P1.y
	1    P2.x    P2.y
    1    P3.x    P3.y
	*/
	Determinant = ((P2.first - P1.first) * (P3.second - P1.second) - (P2.second - P1.second) * (P3.first - P1.first));

	//Points form right turn only if the determinant is less than 0 (Equal to zero means colinear)
	return (Determinant < 0);
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int Number_of_Points, X, Y, i;

	vector <pair<int,int>> Points, Upper_Hull, Lower_Hull;

	set <pair <int,int>> Convex_Hull;

	cin>>Number_of_Points;

	//Enter the points as (X,Y) coordinates
	for(i = 0; i < Number_of_Points; i++){
		cin>>X>>Y;
		Points.push_back(make_pair(X,Y));
	}

	//Sort the points first by X coordinate and then by Y coordinate
	sort(Points.begin(),Points.end());

	//Form the upper half of convex hull
	Upper_Hull.push_back(Points[0]);
	Upper_Hull.push_back(Points[1]);

	for(i = 2; i < Number_of_Points; i++){
		Upper_Hull.push_back(Points[i]);
		while(Upper_Hull.size() >= 3){
			if(Is_Right_Turn(Upper_Hull))
				break;
			else
				//Remove the middle point from the hull
				Upper_Hull.erase(Upper_Hull.end() - 2);
		}
	}

	//Form the lower half of the hull
	Lower_Hull.push_back(Points[Number_of_Points - 1]);
	Lower_Hull.push_back(Points[Number_of_Points - 2]);

	for(i = Number_of_Points-3; i>= 0; i--){
		Lower_Hull.push_back(Points[i]);
		while(Lower_Hull.size() >= 3){
			if(Is_Right_Turn(Lower_Hull))
				break;
			else
				//Remove the middle point from the hull
				Lower_Hull.erase(Lower_Hull.end() - 2);
		}
	}

	//Merge the Upper and Lower Hulls
	for(auto &upper:Upper_Hull)
		Convex_Hull.insert(upper);
	for(auto &lower:Lower_Hull)
		Convex_Hull.insert(lower);

	//Print the Convex Hull
	for(auto &point:Convex_Hull)
		cout<<"("<<point.first<<", "<<point.second<<")\n";

	return 0;

}
