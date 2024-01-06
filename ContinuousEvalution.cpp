#include <bits/stdc++.h>
using namespace std;

class Assignment
{
public:
    string RollNo;
    string CourseCode;
    int Sem;
    int ClassTestMark;
    int SessionalMark;
    int AssignmentMark;
    int TotalMark;
    
    Assignment(string RollNo, string CourseCode, int Sem, int ClassTestMark, int SessionalMark, int AssignmentMark)
    {
        this->RollNo = RollNo;
        this->AssignmentMark = AssignmentMark;
        this->ClassTestMark = ClassTestMark;
        this->CourseCode = CourseCode;
        this->Sem = Sem;
        this->SessionalMark = SessionalMark;
        this->TotalMark = AssignmentMark + ClassTestMark + SessionalMark;
    }
   
};

vector<Assignment> Details;

void AddMark()
{
    string RollNo, CourseCode;
    int Sem, ClassTestMark, SessionalMark, AssignmentMark, TotalMark;
    cout << "Enter RollNo: ";
    cin >> RollNo;
    cout << "Enter CourseCode: ";
    cin >> CourseCode;
    cout << "Enter Class Test Mark: ";
    cin >> ClassTestMark;
    cout << "Enter Sessional Mark: ";
    cin >> SessionalMark;
    cout << "Enter Innovative Assignment Mark: ";
    cin >> AssignmentMark;
    cout << "Enter Semester: ";
    cin >> Sem;
    Assignment data(RollNo, CourseCode, Sem, ClassTestMark, SessionalMark, AssignmentMark);

    Details.push_back(data);
}

void UpdateMark()
{

    string nrn, ncn;
    cout << "Enter RollNo of Student to Update Mark: ";
    cin >> nrn;
    cout << "Enter CourseCode of Subject to Update Mark: ";
    cin >> ncn;
    int nclsm, nsm, nam;
    for (auto &it : Details)
    {
        if (it.RollNo == nrn && it.CourseCode == ncn)
        {
            while(true){
                cout << "Choose an option:" << endl;
                cout << "1. Update Class Test Mark: "<<endl;
                cout << "2. Update  Sessional Mark: "<<endl;
                cout << "3. Update  Assignment Mark: "<<endl;
                cout << "4. Exit"<<endl;
                int choice;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        cout << "Enter new Class Test Mark: ";
                        cin >> nclsm;
                        it.ClassTestMark = nclsm;
                        break;
                    case 2:
                        cout << "Enter new Sessional Mark: ";
                        cin >> nsm;
                        it.SessionalMark = nsm;
                        break;
                    case 3:
                        cout << "Enter new Assignment Mark: ";
                        cin >> nam;
                        it.AssignmentMark = nam;
                        break;
                    case 4:
                        it.TotalMark = it.AssignmentMark  + it.SessionalMark + it.ClassTestMark;
                        return ;
                    default:
                        break;
                }
            }
            return;
        }
    }
    cout << "No Data Found! \n";
}
void DeleteMark()
{
    string drn, dcc;
    cout << "Enter RollNo of Student to Delete Mark: ";
    cin >> drn;
    cout << "Enter CourseCode of Subject to Delete Mark: ";
    cin >> dcc;
    for (auto it = Details.begin(); it != Details.end(); ++it)
    {
        if (it->CourseCode == dcc && it->RollNo == drn)
        {
            it = Details.erase(it);
            cout << "Mark for RollNo: " << drn << " in CourseCode: " << dcc << " has been deleted." << endl;
            return;
        }
    }
    cout << "Data Not Found!" << endl;
}
void MarkSheet()
{
    bool flag = false;
    string coursecode;
    int sem;
    cout << "Enter CourseCode for marksheet: ";
    cin >> coursecode;
    cout << "Enter Semester for marksheet: ";
    cin >> sem;
    cout << "\n\n";
    cout << "RollNo  \tCourseCode\tClassTestMark\tSessionalMark\tAssignmentMark\tTotalMark\tSemester\n";
    for (auto it : Details)
    {
        if (it.Sem == sem && it.CourseCode == coursecode)
        {
            flag = true;
            cout << it.RollNo << "  \t" << it.CourseCode << "\t\t" << it.ClassTestMark << "\t\t" << it.SessionalMark << "\t\t" << it.AssignmentMark << "\t\t" << it.TotalMark << "\t\t" << it.Sem << endl;
        }
    }
    cout<<endl;
    if(!flag)
    cout<<"Data not Found!"<<endl;
}
void FailureReportSem()
{
    map<string,vector<int>> m;
    int sem;
    cout << "Enter Semester for failure report: ";
    cin >> sem;
    vector<pair<int, int>> Fail;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int i = 0;
    for (auto it : Details)
    {
        if (it.Sem == sem && it.TotalMark < 40)
        {
            pq.push({it.TotalMark, i});
        }
        i++;
    }
    if (pq.size() == 0)
    {
        cout << "Data Not Found!\n";
    }
    else
    {
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int index = p.second;
            m[Details[index].CourseCode].push_back(index);
        }
        for(auto it : m){
            cout<< "CourseCode = "<<it.first<<endl;
            cout<<endl;
            cout << "RollNo  \tClassTestMark\tSessionalMark\tAssignmentMark\tTotalMark\t Semester\n";
            for(auto ip : it.second){

                cout << Details[ip].RollNo << "\t\t" << Details[ip].ClassTestMark << "\t\t" << Details[ip].SessionalMark << "\t\t" << Details[ip].AssignmentMark << "\t\t" << Details[ip].TotalMark << "\t\t" << Details[ip].Sem << endl;
            }
            cout<<endl;
        }
    }
}

void Scoller()
{
    string crs;
    cout << "Enter Course Code: ";
    cin >> crs;
    vector<pair<int, int>> sclr;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    int i = 0;
    for (auto it : Details)
    {
        if (it.CourseCode == crs && it.TotalMark >= 40 && i < 5)
        {
            pq.push({it.TotalMark, i});
        }
        i++;
    }
    if (pq.size() == 0)
    {
        cout << "Data Not Found!\n";
    }
    else
    {
        
        cout << "RollNo  \tCourseCode\tClassTestMark\tSessionalMark\tAssignmentMark\tTotalMark\tSemester\n";
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int index = p.second;
            cout << Details[index].RollNo << "  \t" << Details[index].CourseCode << "\t\t" << Details[index].ClassTestMark << "\t\t" << Details[index].SessionalMark << "\t\t" << Details[index].AssignmentMark << "\t\t" << Details[index].TotalMark << "\t\t" << Details[index].Sem << endl;
            
        }
    }
}
int main()
{
    while (true)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add student marks" << endl;
        cout << "2. Delete student marks" << endl;
        cout << "3. Update student marks" << endl;
        cout << "4. Generate marksheet" << endl;
        cout << "5. Generate failure report according to Semester" << endl;
        cout << "6. Generate Course Wise Scoller List" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddMark();
            break;
        case 2:
            DeleteMark();
            break;
        case 3:
            UpdateMark();
            break;
        case 4:
            MarkSheet();
            break;
        case 5:
            FailureReportSem();
            break;
        case 6:
            Scoller();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
