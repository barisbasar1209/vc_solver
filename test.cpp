#include<iostream>
#include<string>

class Test{
	public: 
		int count = 0; 
		std::string phrase = ""; 
		Test(std::string input){
			phrase = input; 	
		}
}; 

int main(void){
	Test t("test"); 
	Test *tt = &t; 

	std::cout<<"t phrase: "<<t.phrase<<'\n'; 
	std::cout<<"tt phrase: "<<(*tt).phrase<<'\n'; 
	std::cout<<"t count: "<<t.count<<'\n'; 
	std::cout<<"tt count: "<<(*tt).count<<'\n'; 
	t.count++; 
	std::cout<<"t count increment: "<<t.count<<'\n'; 
	std::cout<<"tt count increment: "<<(*tt).count<<'\n'; 
	(*tt).phrase = "change"; 
	std::cout<<"t phrase change: "<<t.phrase<<'\n'; 
	std::cout<<"tt phrase change: "<<(*tt).phrase<<'\n'; 

	return 0; 
}
