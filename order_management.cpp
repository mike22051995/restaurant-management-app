#include<iostream>
#include<vector>
#include<queue>
#include<memory>
using namespace std;

class FoodItem{
    public:
    virtual void prepare()=0;
    virtual int GetCost()=0;
    virtual int GetPrepTime()=0;
    virtual string GetName()=0;
};
class pizza:public FoodItem{
    public:
    void prepare()override{
        cout<<"preparing pizza "<<endl;

    }
    int GetCost() override{
        return 100;
    }
    int GetPrepTime() override{
        return 5;
    }
    string GetName() override{
        return "Pizza";

    }       
};
class Burger:public FoodItem{
    public:
    void prepare()override{
        cout<<"preparing Burger "<<endl;

    }
    int GetCost() override{
        return 90;
    }
    int GetPrepTime() override{
        return 10;
    }
    string GetName() override{
        return "Burger";

    }
};
class Pasta:public FoodItem{
    public:
    void prepare()override{
        cout<<"preparing Pasta "<<endl;

    }
    int GetCost() override{
        return 200;
    }
    int GetPrepTime() override{
        return 15;
    }
    string GetName() override{
        return "Pasta";

    }
};
class FoodFactory{
    public:
    static FoodItem* create(const string& food){
        if(food=="pizza") return new pizza();
        else if(food=="burger") return new Burger();
        else if(food=="pasta") return new  Pasta();
        else return nullptr;
        
    }
};
class Kitchen{
    queue<unique_ptr<FoodItem>>orderqueue;
    public:
    void Addorder(FoodItem* food){
        cout<<"Order Recieved:_"<<food->GetName()<<endl;
        orderqueue.emplace(food);
    }
    void ProcessOrders(){
        int ordernumber=1;
        int cost=0;
        while(!orderqueue.empty()){
            auto& food=orderqueue.front();
            cout<<"order:"<<ordernumber++<<food->GetName()<<endl;
            food->prepare();
            cout<<"cost of "<<food->GetName()<<"INR:_"<<food->GetCost()<<endl;
            cout<<"please wait for "<<food->GetPrepTime()<<endl;
            cost+=food->GetCost();
            cout<<"____________________________________________"<<endl;
            orderqueue.pop();
        }
        cout<<"total cost for your order:="<<cost<<endl;
    }
};
int main(){
    Kitchen k1;
k1.Addorder(FoodFactory::create("burger"));
k1.Addorder(FoodFactory::create("pasta"));
k1.Addorder(FoodFactory::create("burger"));
k1.ProcessOrders();
return 0;
}