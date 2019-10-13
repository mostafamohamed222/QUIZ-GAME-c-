#include <bits/stdc++.h>

using namespace std;

int main()
{
    string qu[1000] ;
    string ans[4000] ;
    int scores[500];
    int quiz_number = 0;
    int i =  1;
    int qp = 0;
    int ap = 0;
    int del = 0;
    string line ;
    string username = "USER";

    while(1)
    {
        int choice ;

        cout<<"Welcome "<<username<<", please choose from the following options:\n";
        cout<<"\t[1] Go to administration menu\n\t[2] Update your name\n\t[3] Start a new quiz\n\t[4] Display your scores statistics\n\t[5] Display all your scores\n\t[6] Exit\n";

        cin>>choice;

        if(choice == 1)
        {
            cout<<"Welcome to the administration menu, please choose from the following options:\n";
            cout<<"[1] View all questions\n\t[2] Add new question\n\t[3] Load questions from file\n\t[4] Go back to main menu\n\tMy choice: _";
            cin>>choice;
            if (choice == 1)
            {
                int quesindx = 1 ;
                cout<<"Number of questions available: "<<qp-del<<endl;
                cout<<"Questions list:"<<endl;
                cout<<"-------------------------------------------------------------------------------------"<<endl;
                for(int x = 0 ; x < qp ; x++)
                {
                    if(qu[x]=="")
                    {
                        continue;
                    }
                    cout<<"["<<quesindx++<<']'<<qu[x]<<endl;
                    char ind = 'a';
                    for(int z = x*4 ; z<=(x*4)+3 ; z ++)
                    {
                        cout<<"["<<ind++<<"]"<<ans[z]<<"\t";
                    }
                    cout<<endl;
                }

                cout<<"-------------------------------------------------------------------------------------"<<endl;
                cout<<"Press [d] and the question ID if you want to delete a question (Example: d 2)"<<endl;
                cout<<"Press [b] if you want to go back to the main menu"<<endl;
                char ch ;
                cin>>ch;
                if (ch == 'd')
                {
                    int delind ;
                    cin>>delind;
                    if(qu[delind] == "")
                    {
                        cout<<"index wrong"<<endl;
                    }
                    else
                    {
                        delind--;
                        qu[delind] = "";
                        for(int z = delind*4 ; z<=(delind*4)+3 ; z ++)
                        {
                            ans[z]="";
                        }
                        cout<<"delete it"<<endl;
                        del++;
                    }
                }

            }
            else if (choice == 2)
            {
                string xx ;
                cout<<"enter new question"<<endl;
                cin.ignore();
                getline(cin,xx);
                qu[qp++] = xx;
                for (int i = 0 ; i < 4 ; i ++)
                {
                    cout<<"answer "<<i<<endl;
                    getline(cin,xx);
                    ans[ap++]=xx;
                }
            }
            else if(choice == 3)
            {
                ifstream file;
                file.open("exam_questions.txt");

                while (getline(file, line)) {

                    if (i%5 == 1)
                    {
                        qu[qp++] = line.c_str();
                    }
                    else
                    {
                        ans[ap++] = line.c_str();
                    }
                    i++;
                }
                file.close();

            }
        }
        else if(choice == 2)
        {
            cout<<"enter new user name"<<endl;
            cin>>username;
        }
        else if(choice ==3)
        {
            if(qp-del < 5)
            {
                cout<<"number of question is low"<<endl;
            }
            else
            {
                int quiz_score = 0 ;
                int number_of_question_in_quiz[5] ;
                int ind_in_quiz = 0;

                for(int r = 0 ; r <5 ; r++)
                {
                    int new_number = rand()%qp;
                    if(qu[new_number] =="")
                    {
                        r--;
                        continue;
                    }
                    bool flage = true;
                    for(int ch = 0 ; ch<ind_in_quiz ; ch++)
                    {
                        if(new_number == number_of_question_in_quiz[ch])
                        {
                            flage = false;
                        }
                    }
                    if(flage)
                    {
                        number_of_question_in_quiz[ind_in_quiz++] = new_number;
                    }
                    else
                    {
                        r--;
                    }
                }
                for(int p =0 ; p < ind_in_quiz ; p ++)
                {
                    int question_number = number_of_question_in_quiz[p];
                    string answer_for_question[4];
                    string correct_answer = "";
                    int set_in = 0;

                    for(int z = question_number*4 ; z<=(question_number*4)+3 ; z ++)
                    {
                        if(set_in == 0)
                        {
                            correct_answer = ans[z];
                        }
                        answer_for_question[set_in++] = ans[z];
                    }

                    cout<<"question number "<<p+1<<":"<<endl;
                    cout<<qu[question_number]<<endl;

                    int number_of_answer_in_quiz[4] ;
                    int ind_answer_in_quiz = 0;
                    for(int r = 0 ; r <4 ; r++)
                    {
                        int new_number = rand()%4;
                        bool flage = true;
                        for(int ch = 0 ; ch<ind_answer_in_quiz ; ch++)
                        {
                            if(new_number == number_of_answer_in_quiz[ch])
                            {
                                flage = false;
                            }
                        }
                        if(flage)
                        {
                            number_of_answer_in_quiz[ind_answer_in_quiz++] = new_number;
                        }
                        else
                        {
                            r--;
                        }
                    }

                    char ss='1';
                    for(int out = 0 ; out<4 ; out++)
                    {
                        int pri = number_of_answer_in_quiz[out];
                        cout<<"["<<ss++<<"] "<<answer_for_question[pri]<<" ";
                    }
                    cout<<endl;

                    cout<<"your answer is ";
                    int answer = 0;
                    cin>>answer;
                    answer--;
                    string your_answer = answer_for_question[number_of_answer_in_quiz[answer]];
                    if(your_answer == correct_answer)
                    {
                        quiz_score+=2;
                    }
                }
                cout<<quiz_score<<endl;
                scores[quiz_number++] = quiz_score;
            }
        }
        else if(choice == 4)
        {
            int Highest_score = 0 ;
            int lowest_score = 11;
            float average_score = 0 ;


            for(int quiz = 0; quiz < quiz_number ; quiz++)
            {
                Highest_score = max(Highest_score,scores[quiz]);
                lowest_score = min(lowest_score,scores[quiz]);
                average_score += scores[quiz];
            }

            cout<<"Your score statistics:"<<endl;
            cout<<"-------------------------------"<<endl;
            cout<<"\tNumber of Quizzes taken : "<<quiz_number<<endl;
            cout<<"\tHighest_score : "<<Highest_score<<endl;
            cout<<"\tlowest_score  : "<<lowest_score<<endl;
            cout<<"\taverage_score : "<<average_score/(quiz_number)<<endl;
            cout<<"Press [b] if you want to go back to the main menu or [e] to exit"<<endl;
            char xx ;
            cin>>xx;
            if(xx == 'e')
            {
                return 0;
            }
        }
        else if(choice == 5)
        {
            cout<<"the quiz scores is :"<<endl;

            for(int quiz = 0 ; quiz < quiz_number ; quiz++)
            {
                cout<<"the quiz number "<<quiz+1<<" score is"<<scores[quiz]<<endl;
            }
        }
        else
        {
            return 0 ;
        }
    }

    return 0;
}
