#pragma once
#include "Word.h"

class imennyk :public Word {
public:
    imennyk(string f=""){
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


};
