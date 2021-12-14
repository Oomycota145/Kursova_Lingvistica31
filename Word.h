#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Word{

private:
    string type; //іменник, прикметник і т д
    string rod; // жін, чол, сер
    int mnoj;// 1-однина 2-множина
    string padej;// відмінки
    vector<string> prefix;//0 3
    vector<string> root;//1 2
    vector<string> suffix;//0 3
    string ending;//0 1
public:



    vector<string>& get_prefix() { return prefix; }
    vector<string>& get_root() { return root; }
    vector<string>& get_suffix() { return suffix; }
    string get_ending() { return ending; }

    string get_type() { return type; };
    string get_rod() { return rod; };
    int get_mnoj() { return mnoj; };
    string get_padej() { return padej; };



    void change_prefix(vector<string>& new_prefix){
         this->prefix = new_prefix;
    }
    void change_root(vector<string>& new_root){
         this-> root= new_root;
    }
    void change_suffix(vector<string>& new_suffix){
         this->suffix = new_suffix ;
    }

    void change_ending(string new_ending) {
        this->ending =new_ending;
    }
    void set_type (string _type ) { this->type  =_type  ; }
    void set_rod (string _rod ) { this-> rod = _rod ; }
    void set_mnoj (int _mnoj ) { this->mnoj  = _mnoj ; }
    void set_padej (string _padej ) { this-> padej = _padej ; }
    void change_rod (string _rod,vector<string>& new_root,vector<string>& new_suffix,string new_ending)
    {
        change_ending(new_ending);
        change_root(new_root);
        change_suffix(new_suffix);
        set_rod (_rod);

    }
    void change_padej (string  _padej,vector<string>& new_root,string new_ending)
    {
        change_ending(new_ending);
        change_root(new_root);
        set_padej (_padej);

    }
    void change_mnoj (int _mnoj,vector<string>& new_root,string new_ending)
    {
        change_ending(new_ending);
        change_root(new_root);
        set_mnoj (_mnoj);

    }
    string slovocel() {
        string temp;
        for (auto& p : prefix) {
            temp += p;
        }
        for (auto& r : root) {
            temp += r;
        }
        for (auto& s : suffix) {
            temp += s;
        }
        for (auto& e : ending) {
            temp += e;
        }
        return temp;
    }
    Word(string f=""){
        vector<string> p,r,s;
        string e,s1,s2,s3,s_dop;
        int mn,n_p;
         if(f=="c")
        {

            cout<<"введіть параметри Слова в такій послідовності: тип_слова\n рід 1(однина)/2(множина) відмінок\n";
            cin>>s1>>s2>>mn>>s3;
            cout<<"";
            cin>>n_p;
            for(int ij=0;ij<n_p;ij++){
                    cin>>s_dop;
                    p.push_back(s_dop);
                }
            cin>>n_p;
            for(int ij=0;ij<n_p;ij++){
                    cin>>s_dop;
                    r.push_back(s_dop);
                }
            cin>>n_p;
            for(int ij=0;ij<n_p;ij++){
                    cin>>s_dop;
                    s.push_back(s_dop);
                }
            cin>>n_p;
            if(n_p==1){ cin>>e;}
        }
        else
        {
            ifstream file; // создаем объект класса ifstream
            file.open(f); // открываем файл
            if(!file){cout<< "за даним шляхом файл не знайдено"; }
            else{

                file>>s1>>s2>>mn>>s3;

                file>>n_p;
                for(int ij=0;ij<n_p;ij++){
                        file>>s_dop;
                        p.push_back(s_dop);
                    }
                file>>n_p;
                for(int ij=0;ij<n_p;ij++){
                        file>>s_dop;
                        r.push_back(s_dop);
                    }
                file>>n_p;
                for(int ij=0;ij<n_p;ij++){
                        file>>s_dop;
                        s.push_back(s_dop);
                    }
                file>>n_p;
                if(n_p==1){ file>>e;}

            }

        file.close();
        }

        set_type(s1);
        set_rod(s2);
        set_mnoj(mn );
        set_padej(s3);
        change_prefix(p);
        change_root(r);
        change_suffix(s);
        change_ending(e);}

    int golos( string sym)
    {

        string glas("аяиіеуїєюо");
        for(int i =0;i<20;i+=2){

        if (sym==string(glas,i,2)) {
        return 1;}
        }

        return 0;
    }


    int glas_u_glas(string s,int i)
    {
        if (s.size()-i>5) return (golos(string(s,i,2))&&golos(string(s,i+4,2))&&(string(s,i+2,2)=="й"));
        else return 0;
    }
    int glas_m_zn_glas(string s,int i)
    {
        if (s.size()-i>5) return (!golos(string(s,i,2))&&!golos(string(s,i+4,2))&&(string(s,i+2,2)=="ь"));
        else return 0;
    }
    int find_g(string s)
    {
        for(int i=0;i<s.size();i+=2)
        {
            if(golos(string(s,i,2))==1) {return i;}
        }
        return -1;
    }
    string slog(string s){

        string res;
        int i=0;
        while(s.size()!=0)
        {
            i=find_g(s);

            if(i==-1||i==s.size()-2)  {res+=s;s="";}
            else
            {
                if(((golos(string(s,i,2))&&golos(string(s,i+2,2))))||glas_u_glas(s,i))
                {
                    if(golos(string(s,i,2))&&golos(string(s,i+2,2))) {res+=string(s,0,i+2);res+="-"; s=string(s,i+2,s.size()-i);}
                    else{ res+=string(s,0,i+4);res+="-"; s=string(s,i+4,s.size()-i+2);}

                }
                else
                {
                    i+=2;

                    if((!golos(string(s,i,2)))&&(!golos(string(s,i+2,2)))||glas_m_zn_glas(s,i))
                    {
                    if((!golos(string(s,i,2)))&&(!golos(string(s,i+2,2)))&&(string(s,i+2,2)!="ь")) {res+=string(s,0,i+2)+"-"; s=string(s,i+2,s.size()-i);}
                    else {res+=string(s,0,i+4)+"-"; s=string(s,i+4,s.size()-i-2);}
                    }


                    else{ if((golos(string(s,i-2,2)))&&(!golos(string(s,i,2)))) {res+=string(s,0,i)+"-"; s=string(s,i,s.size()-i+4);}
                }}
            }

        }
        res=string(res,0,res.size());
        return res;

    }
    void output(string f="")
    {
        vector<string> p,r,s;
        string e,s1,s2,s3,s_dop;
        int mn,n_p;
        p=get_prefix();
        r=get_root();
        s=get_suffix();
        e=get_ending() ;
        s1=get_type();
        s2=get_rod() ;
        mn=get_mnoj() ;
        s3=get_padej();
         if(f=="c")
        {

            cout<<s1<<" "<<s2<<" "<<mn<<" "<<s3;
            cout<<"\n";
            cout<<p.size();
            cout<<"\n";
            for(int ij=0;ij<p.size();ij++){
                    cout<<p[ij]<<" ";
                }
            cout<<r.size()<<"\n";
            for(int ij=0;ij<r.size();ij++){
                    cout<<r[ij]<<" ";
                }

            cout<<s.size()<<"\n";

            for(int ij=0;ij<s.size();ij++){
                    cout<<s[ij]<<" ";
                }
            cout<<e;
        }
        else
        {
            ofstream file;// Создаем файл
            file.open(f); // открываем файл

            file<<s1<<" "<<s2<<" "<<mn<<" "<<s3;
            file<<"\n";
            file<<p.size();
            file<<"\n";
            for(int ij=0;ij<p.size();ij++){
                    file<<p[ij]<<" ";
                }
            file<<r.size()<<"\n";
            for(int ij=0;ij<r.size();ij++){
                    file<<r[ij]<<" ";
                }

            file<<s.size()<<"\n";

            for(int ij=0;ij<s.size();ij++){
                    file<<s[ij]<<" ";
                }
            file<<e;




        file.close();
        }
    }


};

