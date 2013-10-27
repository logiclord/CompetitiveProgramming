#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cmath>
#include<set>
#include<string>
#define Pi 3.141592653589793
#define INF 999999999
#define EPS 1e-9

using namespace std;

double gcDistance(pair<double, double> p1, pair<double, double> p2)
{
	return 6378.0*acos(cos(p1.first)*cos(p1.second)*cos(p2.first)*cos(p2.second) + 
		cos(p1.first)*sin(p1.second)*cos(p2.first)*sin(p2.second)  + sin(p1.first)*sin(p2.first));

}


double spherical_distance(double lat1,double lon1,double lat2,double lon2) {

	double dlon = lon2 - lon1;
	double dlat = lat2 - lat1;
	double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	double d = 6378.0 * c;

	return d;
}


int main()
{
	map<string, pair<double, double> > data;
	string temp, temp2;
	double lat, lon;

	while(cin>>temp && temp[0]!='#')
	{
		cin>>lat>>lon;
		data[temp] = make_pair(lat*Pi/180.0, lon*Pi/180.0);
	}


	while(cin>>temp>>temp2 && (temp[0]!='#' || temp2[0]!='#'))
	{
		cout<<temp<<" - "<<temp2<<endl;
		if(data.find(temp)!=data.end() && data.find(temp2)!=data.end())
		{
			cout<<(int)(0.5 + spherical_distance(data[temp].first,data[temp].second, data[temp2].first, data[temp2].second))<<" km\n";
			//cout<<(int)(0.5 + gcDistance(data[temp], data[temp2]))<<" km\n";
		}
		else
		{
			cout<<"Unknown\n";
		}
	}


	return 0;
}
