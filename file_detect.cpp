#include <fstream>
#include <bits/stdc++.h>
using namespace std;


struct object{
	string class_name;
	int left, right , top, bot;
};

void left_hand(struct object a, struct object b){

	cout<<a.class_name<<" is left to "<<b.class_name<<endl<<endl;
}

void right_hand(struct object a, struct object b){
	cout<<a.class_name<<" is right to "<<b.class_name<<endl<<endl;
}


int main(){
ifstream infile("file_detect.txt");



int count = 0;
struct object detections[100];

string a;
int b, c ,d, e;
while (infile >> a >> b >> c>> d>> e)
{
    
    detections[count].class_name = a;
    detections[count].left = b;
    detections[count].right = c;
    detections[count].top = d;
    detections[count].bot = e;

    count++;
}

infile.close();

ofstream outfile("feedback.txt");

int i=0,j=0;

for(i=0;i<count;i++){
	for(j=i+1;j<count;j++){

			if(detections[i].left > detections[j].right){

				outfile<<detections[i].class_name<<" is right to "<<detections[j].class_name<<endl<<endl;
			}
			else if(detections[i].right < detections[j].left){

				outfile<<detections[i].class_name<<" is left to "<<detections[j].class_name<<endl<<endl;
			}
			else if(detections[i].left < detections[j].left and detections[i].right < detections[j].right){

				outfile<<detections[i].class_name<<" is left to "<<detections[j].class_name<<endl<<endl;
			}
			else if(detections[i].right > detections[j].right and detections[i].left > detections[j].left){

				outfile<<detections[i].class_name<<" is right to "<<detections[j].class_name<<endl<<endl;			}
			else
				outfile<<detections[i].class_name<< " and "<<detections[j].class_name<<" are in front of you"<<endl<<endl;
		}
}

outfile.close();
system("espeak -v en-us -s 135 --stdout -f feedback.txt | aplay ");

return 0;
}