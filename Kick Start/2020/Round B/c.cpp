#include<bits/stdc++.h>

using namespace std;

int i;

//void optimize() {
	//int T;
	
	//cin >> T;
	//string prog;
	
	//for(int t = 0; t < T; t++) {
		//cin >> prog;
		
		//stack<char> s;
		//stack<pair<int, int>> val;
		
		//for(int i = 0; i < prog.size(); i++) {
			//if(prog[i] == '(') {
				//continue;
			//} else if(prog[i] == ')') {
				//int t_w = 0, t_h = 0;
				
				//while(!s.empty()) {
					//cout << s.top() <<  " "; 
					//if(s.top() > '0' && s.top() <= '9') {
						//int c = s.top() - '0';
						//s.pop();
						//t_w = t_w * c;
						//t_h = t_h * c;
						//val.push(make_pair(t_w, t_h));
						//s.push('P');
						//break;
					//}
					
					//if(s.top() == 'E') {
						//t_w += 1;
					//} else if(s.top() == 'W') {
						//t_w += -1;
					//} else if(s.top() == 'S') {
						//t_h += 1;
					//} else if(s.top() == 'P') {
						//pair<int, int> p = val.top();
						//t_w += p.first;
						//t_h += p.second;
						//val.pop();
					//}
					//else {
						//t_h += -1;
					//}
					
					//s.pop();
				//}
				
				//cout << endl;
			//} else {
				//s.push(prog[i]);
			//}
		//}
		
		//int w = 0, h = 0;
		
		//while(!s.empty()) {
			//cout << s.top() << " ";
			//if(s.top() == 'P') {
				//pair<int, int> p = val.top();
				//w += p.first;
				//h += p.second;
				//val.pop();
			//}
			//else if(s.top() == 'E') {
				//w += 1;
			//} else if(s.top() == 'W') {
				//w += -1;
			//} else if(s.top() == 'S') {
				//h += 1;
			//} else {
				//h += -1;
			//}
			
			//w += 1000000000;
			//h += 1000000000;
			
			//w = w % 1000000000;
			//h = h % 1000000000;
			
			//s.pop();
		//}

		//cout << endl;

		//cout << "Case #" << t << ": " << (w + 1) << " " << (h + 1) << endl;
	//}
//}

//void nonOptimize() {
	//int T;
    
    //cin >> T;

    //string prog;
    
    //stack<char> s;
    
    //for(int t = 1; t <= T; t++){
        //cin >> prog;
        
        //for(int i = 0; i < prog.size(); i++) {
			//if(prog[i] == '(') {
				//continue;
			//}
			//else if(prog[i] == ')') {
				//string temp = "";
				//while(!s.empty()) {
					//if(s.top() > '0' && s.top() <= '9') {
						//int c =  s.top() - '0';
						//s.pop();
						
						//while(c--) {
							//for(int j = 0; j < temp.size(); j++) {
								//s.push(temp[j]);
							//}
						//}
						//break;
					//}
					//temp = s.top() + temp;
					//s.pop();
				//}
			//}
			//else {
				//s.push(prog[i]);
			//}
		//}
		
		//string decode;
		
		//while(!s.empty()) {
			//if(s.top() > '0' && s.top() <= '9') {
				//int c =  s.top() - '0';
				
				//string temp = decode;
				//while(c--) {
					//decode += temp;
				//}
			//}
			//else {
				//decode = s.top() + decode;
			//}
			
			//s.pop();
		//}
        
        //int w = 0, h = 0;
        
        //for(int i = 0; i < decode.size(); i++) {
			//int lr = 0, ud = 0;
			//if(decode[i] == 'E') {
				//lr = 1;
			//} else if(decode[i] == 'W') {
				//lr = -1;
			//} else if(decode[i] == 'S') {
				//ud = 1;
			//} else {
				//ud = -1;
			//}
			
			//w += lr;
			//h += ud;

			//if(w < 0) {
				//w = 1000000000 + w;
			//}
			
			//if(h < 0) {
				//h = 1000000000 + h;
			//}
			
			//w = w % 1000000000;
			//h = h % 1000000000;
		//}
        
        //cout << "Case #" << t << ": " << (w + 1) << " " << (h + 1) << endl;
	//}
//}

pair<int, int> evaluate(string prog) {
	int width = 0, height = 0;
	
	while(i < prog.size()) {
		if(prog[i] == ')'){
		i++;
			break;
		}
		else if(prog[i] > '0' && prog[i] <= '9') {
			int c = prog[i] - '0';
			
			i += 2;
			pair<int, int> p = evaluate(prog);
			
			width += c * p.first;
			width %= 1000000000;
			height += c * p.second;
			height %= 1000000000;
		} else {
			if(prog[i] == 'E') {
				width += 1;
			} else if(prog[i] == 'W') {
				width -= 1;
			} else if(prog[i] == 'S') {
				height += 1;
			} else {
				height -= 1;
			}
			
			i++;
		}
	}
	
	return make_pair(width, height);
}

void recursiveSol() {
	int T;
	
	cin >> T;
	
	for(int t = 1; t <= T; t++) {
		string prog;
		
		cin >> prog;
		
		i = 0;
		pair<int, int> p = evaluate(prog);
		
		int w = p.first;
		int h = p.second;
		
		if(w < 0) {
			w = 1000000000 + w;
		}
		
		if(h < 0) {
			h = 1000000000 + h;
		}
		
		w = w % 1000000000;
		h = h % 1000000000;
	
		cout << "Case #" << t << ": " << (w + 1) << " " << (h + 1) << endl;
	}
}

int main(int argc, const char* argv[]) {
	//nonOptimize();
	//optimize();
	recursiveSol();
	return 0;
}
