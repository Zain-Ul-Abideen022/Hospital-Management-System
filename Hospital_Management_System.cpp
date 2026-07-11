#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdexcept>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    public:
    Person(){ }
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    virtual void display() const{
        cout<<"\nName:"<<name<<"\nAge: "<<age<<endl;
    }
    virtual ~Person(){ }
};

class Staff{
    protected:
    static int totalstaff;
    public:
    Staff(){
        totalstaff++;
    }
    static void Showtotalstaff(){
    cout<<"\nTotal Staff(Doctors): "<<totalstaff<<endl;
}
};
int Staff::totalstaff=0;

class Patient : public Person{
    protected:
    int id;
    string disease;
    static int totalpatients;
    public:
    Patient() { }
    Patient(int id,string n,int a,string disease):Person(n,a){
         try{
        if(id<=0)
        throw invalid_argument("Invalid Input.ID must be greater than zero !\n");
        if(a<1 || a>150)
        throw invalid_argument("Invalid Input.Age must be between 1 to 150");
    
        this->id=id;
        this->disease=disease;
        totalpatients++;
         }
     catch(invalid_argument &e) {
                cout<<e.what()<<endl;
                this->id = 0;
                this->disease="";
            }
        }
   static void ShowTotalPatients(){
        cout<<"\nTotalPatients are: "<<totalpatients<<endl;
    }
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }
    void setAge(int age){
        this->age=age;
    }
    int getAge(){
        return age;
    }
    void setDisease(string disease){
        this->disease=disease;
    }
    string getDisease(){
        return disease;;
    }
    int getId(){
        return id;
    }
    void display() const{
        cout<<"\nPatient Id: "<<id<<endl;
        Person::display();
        cout<<"Disease is: "<<disease<<endl;

    }
    bool operator==(const Patient &p)const{
        return id==p.id;
    }
};
int Patient::totalpatients=0;

class Inpatient:public Patient{
    private:
    int WardNum;
    string AdmitDate;
    public:
    Inpatient() {}
    Inpatient(string n,int a,int i,string d,int ward,string date):Patient(i,n,a,d){
        WardNum=ward;
        AdmitDate=date;
    }
    void setWardNum(int WardNum){
        this->WardNum=WardNum;
    }
    void setAdmitDate(string date){
        AdmitDate=date;
    }
    int getWardNum()const{
        return WardNum;
    }
    string getAdmitDate()const{
        return AdmitDate;
    }
    void display() const{
        Patient::display();
        cout<<"WardNum is: "<<WardNum<<endl;
        cout<<"Admit Date is: "<<AdmitDate<<endl;
    }
};

class Doctor:public Person,public Staff{
    private:
    int id;
    string department;
    public:
    Doctor(){ }
    Doctor(int id,string n,int a,string dept):Person(n,a){
        this->id=id;
        department=dept;
    }
    void setName(string name){
        this->name=name;
    }
    void setAge(int age){
        this->age=age;
    }
    void setDept(string dept){
        department=dept;
    }
    int getId() const{
        return id;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getDept(){
        return department;
    }
    void display() const{
        cout<<"\nDoctor ID: "<<id<<endl;
        Person::display();
        cout<<"Department: "<<department<<endl;
    }
    bool operator==(const Doctor &d)const{
        return this->id==d.id;
    }
};
class Medicine{
    private:
    string name;
    int quantity;
    static int totalMedicines;
    public:
    Medicine(){}
    Medicine(string n,int q){
        name=n;
        quantity=q;
        totalMedicines++;
    }
    static void ShowtotalMedicines(){
        cout<<"Total medicines are: "<<totalMedicines<<endl;
    }
    void setName(string n){
        name=n;
    }
    void setQuantity(int q){
        quantity=q;
    }
    string getName(){
        return name;
    }
    int getQuantity(){
        return quantity;
    }
    void display()const{
        cout<<"Name is: "<<name<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
    Medicine operator+(Medicine &M){
        Medicine temp;
        temp.name=name;
        temp.quantity=quantity+M.quantity;
        return temp;
    }
};
int Medicine::totalMedicines=0;

class Appointment{
    private:
    int Appointment_Id;
    int patientId ;
    int doctorId;
    string time;
    public:
    Appointment(int id,int p,int d,string time){
          try {
             if(id<=0)
            throw invalid_argument("Invalid Appointment ID!");
                if(p<=0)
                    throw invalid_argument("Invalid Patient ID!");
                if(d<=0)
                    throw invalid_argument("Invalid Doctor ID!");
                if(time.empty())
                    throw invalid_argument("Time cannot be Empty!");

                Appointment_Id = id;
                patientId = p;
                doctorId = d;
                this->time = time;
            }
            catch(invalid_argument &e) {
                cout << "Error: "<<e.what()<<endl;
                Appointment_Id = 0;
                patientId = 0;
                doctorId = 0;
                this->time ="";
            }
        }
     int getId()const{
        return Appointment_Id;
     }
     void setTime(string t){
     time=t;
     }

     string getTime(){
        return time;
     }
     int getPatientId() const{
        return patientId;
     }
     int getDoctorId() const{
        return doctorId;
     }
     void display(){
        cout<<"\nAppointment ID: "<<Appointment_Id<<endl;
        cout<<"Patient ID: "<<patientId<<endl;
        cout<<"Doctor ID: "<<doctorId<<endl;
        cout<<"Time: "<<time<<endl;
     }
     bool operator==(const Appointment &a)const{
        return this->Appointment_Id == a.Appointment_Id;
     }
    };
    template<typename T> class Billing;
template<typename T> void Show_BillSummary(Billing<T> b);
    template<typename T>
    class Billing {
        private:
        int patientId;
        T doctorfee;
        T testfee;
        T medicine_dues;
        public:
        Billing(int p_id,T df,T tf,T md){
            try {
                if(p_id<=0)
                    throw invalid_argument("Invalid Patient ID!");
                if(df<0 || tf<0 || md<0)
                    throw invalid_argument("Fee cannot be Negative!");

                patientId = p_id;
                doctorfee = df;
                testfee = tf;
                medicine_dues = md;
            }
            catch(invalid_argument &e) {
                cout<<"Error: "<<e.what()<<endl;
                patientId = 0;
                doctorfee = 0;
                testfee = 0;
                medicine_dues = 0;
            }
        }
        T getTotal() const{
            T total=doctorfee + testfee + medicine_dues;
            return total;
        }
        void display() const{
            cout<<"\nPatientId: "<<patientId<<endl;
            cout<<"Total fee: "<<getTotal()<<endl;
        }
        friend void Show_BillSummary<>(Billing<T>);
    };
    template <typename T>
    void Show_BillSummary(Billing<T> b){
        cout<<"____ Bill Summary ____\n";
        cout<<"Patient Id: "<<b.patientId<<endl;
        cout<<"Doctor fee: "<<b.doctorfee<<endl;
        cout<<"Test fee: "<<b.testfee<<endl;
        cout<<"Medicines dues: "<<b.medicine_dues<<endl;
        cout<<"\nTotal Hospital bill: "<<b.getTotal()<<endl;
    }
    class HospitalSystem{
        private:

        vector<Patient> patients;
        vector<Doctor> doctors;
        vector<Appointment> appointments;
        vector<Medicine> medicines;

        int  PatientCounter=1;
        int  DoctorCounter=1;
        int  AppointmentCounter=1;
        int MedicineCounter=1;

        public:
          
        void saveAll() {        
            savePatients();
            saveDoctors();
            saveAppointments();
            saveMedicines();
        }

        void loadAll() {          
            loadPatients();
            loadDoctors();
            loadAppointments();
            loadMedicines();
        }

        void savePatients(){
              if(patients.empty()) {
        cout << "No Patients has Saved!\n";
        return;                            
    }
            ofstream file("Patients.txt");
            if(!file){
                cout<<"File can't open ! \n";
                return ;
            }
            for(int i=0;i<patients.size();i++){
                file<<patients[i].getId() <<endl;
                file<<patients[i].getName() <<endl;
                file<<patients[i].getAge() <<endl;
                file<<patients[i].getDisease() <<endl;
            }
            file.close();
            cout<<"Patient data Saved !\n";
            }

            void loadPatients(){
                ifstream file("Patients.txt");
                if(!file){
                    cout<<"File not found ! \n";
                    return ;
                }
                int id,age;
                string name,disease;
                while (file>>id>>name>>age>>disease){
                    patients.push_back(Patient(id,name,age,disease));
                    if(id>=PatientCounter){
                        PatientCounter = id + 1;
                    }
                }
                    file.close();
                    cout<<"Patient data loaded ! \n";
            }
            void saveDoctors(){
                 if(doctors.empty()) {
        cout << "No Doctors has Saved!\n";
        return;                           
    }
                ofstream file("Doctor.txt");
                if(!file){
                    cout<<"File can't open ! \n";
                    return ;
                }
                for(int i=0;i<doctors.size();i++){
                    file<<doctors[i].getId() <<endl;
                    file<<doctors[i].getName() <<endl;
                    file<<doctors[i].getAge() <<endl;
                    file<<doctors[i].getDept() <<endl;
                }
                file.close();
                cout<<"Doctor data Saved !\n";
            }

            void loadDoctors(){
                ifstream file("Doctor.txt");
                if(!file){
                    cout<<"File not found !\n";
                    return ;
                }
                int id,age;
                string name,dept;
                while(file>>id>>name>>age>>dept){
                    doctors.push_back(Doctor(id,name,age,dept));
                    if(id>=DoctorCounter){
                        DoctorCounter = id+1;
                    }
                }
                    file.close();
                    cout<<"Doctor data loaded !\n";
                }

            void saveAppointments(){
                 if(appointments.empty()) {
        cout << "No Appointments has saved\n";
        return;
    }
                ofstream file("Appointments.txt");
                if(!file){
                    cout<<"File can't open ! \n";
                    return ;
                }
                for(int i=0;i<appointments.size();i++){
                    file<<appointments[i].getId() <<endl;
                    file<<appointments[i].getPatientId() <<endl;
                    file<<appointments[i].getDoctorId() <<endl;
                    file<<appointments[i].getTime() <<endl;
                }
                file.close();
                cout<<"Appointments data Saved ! \n";
            }

            void loadAppointments(){
                ifstream file("Appointments.txt");
                if(!file){
                    cout<<"File not found ! \n";
                    return ;
                }
                int id, P_id , d_id; 
                string time;
                while(file>>id>>P_id>>d_id>>time){
                    appointments.push_back(Appointment(id,P_id,d_id,time));
                    if(id>=AppointmentCounter)
                        AppointmentCounter = id +1;
                    }
                
                    file.close();
                    cout<<"Appointments data loaded ! \n";
            }
            void saveMedicines(){
                 if(medicines.empty()) {
        cout << "No Medicines has Saved!\n";
        return;                            
    }
                ofstream file("Medicines.txt");
                if(!file){
                    cout<<"File can't open ! \n";
                    return ;
                }
                for(int i=0;i<medicines.size();i++){
                    file<<medicines[i].getName() <<endl;
                    file<<medicines[i].getQuantity() <<endl;
                }
                file.close();
                cout<<"Medicines data saved ! \n";
            }
            void loadMedicines(){
                ifstream file("Medicines.txt");
                if(!file){
                    cout<<"File not found ! \n";
                    return ;
                }
                int quantity;
                string name;
                while(file>>name>>quantity){
                    medicines.push_back(Medicine(name,quantity));
                }
                    file.close();
                    cout<<"Medicines data loaded ! \n";
            }


        void addPatient(){
            string name,disease;
            int age;
            cout<<"Enter Patient name: ";
            cin>>name;
             cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter disease: ";
            cin>>disease;

            patients.push_back(Patient(PatientCounter++,name,age,disease)); 
            cout<<"\nPatient Added !\n";
}
    void viewPatients(){
        for(int i=0;i<patients.size();i++){
            Patient *ptr = &patients[i];
            ptr->display();
        }
        Patient::ShowTotalPatients();


    }
    void updatePatient(){
        int id ;
        cout<<"Enter Patient Id: ";
        cin>>id;
        for(int i=0;i<patients.size();i++){
            if(patients[i].getId()==id){
            string name,disease;
            int age;
            cout<<"Enter the patient name: ";
            cin>>name;
            cout<<"Enter Age: ";
            cin>>age;
            cout<<"Enter disease: ";
            cin>>disease;
            patients[i].setName(name);
            patients[i].setAge(age);
            patients[i].setDisease(disease);

            cout<<"Patient Updated Successfully ! \n"; 
            return ;
        }
    }
    cout<<"Entered ID Invalid ! \n";
}

    void deletePatient(){
        int id;
        cout<<"Enter Patient Id: ";
        cin>>id;
        for(int i=0;i<patients.size();i++){
            if(patients[i].getId()==id){
              patients.erase(patients.begin()+i);
                cout<<"Patient deleted Successfully !";
                return ;
            }
        }
            cout<<"Invalid Entered ID ! ";
    }
    bool patientExist(int id){
        for(int i=0;i<patients.size();i++){
            if(patients[i].getId()==id)
            return true;
        }
            return false;
    }
    void addDoctor(){
        string name,dept;
        int age;
        cout<<"Enter the name of the doctor: ";
        cin>>name;
        cout<<"Enter the department of the doctor: ";
        cin>>dept;
        cout<<"Enter the age of the doctor: ";
        cin>>age;
        
        doctors.push_back(Doctor(DoctorCounter++,name,age,dept));
         cout<<"\nDoctor Added !\n";
    }
    void viewDoctors(){
        for(int i=0;i<doctors.size();i++){
        Doctor *ptr = &doctors[i];
        ptr->display();
        }
        Staff::Showtotalstaff();
    }
    void updateDoctor(){
        int id;
        cout<<"Enter ID: ";
        cin>>id;
        for(int i=0;i<doctors.size();i++){
            if(doctors[i].getId()==id){
                string name,dept;
                int age;
                cout<<"Enter name: ";
                cin>>name;
                cout<<"Enter dept name: ";
                cin>>dept;
                cout<<"Enter age: ";
                cin>>age;
                
                doctors[i].setName(name);
                doctors[i].setDept(dept);
                doctors[i].setAge(age);
                
                cout<<"Doctor Updated Successfully !\n";
                return ;

            }
        } 
            cout<<"Invalid Id Entered !\n ";
        
    }
    void deleteDoctor(){
        int id;
        cout<<"Enter doctor Id: ";
        cin>>id;
        for(int i=0;i<doctors.size();i++){
            if(doctors[i].getId()==id){
               doctors.erase(doctors.begin()+i);
                cout<<"Doctor deleted Successfully ! \n";
                return ;
            }
        }
            cout<<"Invalid ID Entered ! \n";
    }
    bool doctorExist(int id){
        for(int i=0;i<doctors.size();i++){
            if(doctors[i].getId()==id)
            return true;
        }
        return false;
        }
    
    void addMedicine(){
        string name;
        int quantity;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter quantity: ";
        cin>>quantity;

        medicines.push_back(Medicine(name,quantity));
         cout<<"\nMedicine Added !\n";
    }

    void viewMedicines(){
        for(int i=0;i<medicines.size();i++){
            Medicine *ptr = &medicines[i];
            ptr->display();
        }
        Medicine::ShowtotalMedicines();
    }

    void bookAppointment(){
        int P_Id , D_Id;
        string time;

        cout<<"Enter Patient Id: ";
        cin>>P_Id;
        if(!patientExist(P_Id)){
        cout<<"Patient doesn't Exist: ";
        return ;
        }
        cout<<"Enter Doctor Id: ";
        cin>>D_Id;
        if(!doctorExist(D_Id)){
            cout<<"Doctor doesn't Exist ";
            return ;
        }
        cout<<"Enter Appointment time: ";
        cin>>time;

        for(int i=0;i<appointments.size();i++){
            if(appointments[i].getTime()==time){
                cout<<"Sorry this time is already booked Enter another time: ";
                cin>>time;
                i=-1;
            }
        }
        appointments.push_back(Appointment(AppointmentCounter++,P_Id,D_Id,time));
        cout<<"Appointment Done Successfully ! \n";
    }
    
    void viewAppointments(){
        for(int i=0;i<appointments.size();i++){
            Appointment *ptr = &appointments[i];
            ptr->display();
        }
        cout<<"\nNo Appointmetn Yet !\n";
    }
    void updateAppointment(){
        int id;
        string time;
        cout<<"Enter Appointment Id: ";
        cin>>id;
        for(int i=0;i<appointments.size();i++){
            if(appointments[i].getId()==id){
                cout<<"Enter Appointment time: ";
                cin>>time;
                if(appointments[i].getTime()==time){
                    cout<<"Sorry this time is already booked Enter another time: ";
                    cin>>time;
                    i=-1;
                }
                else 
                appointments[i].setTime(time);
                cout<<"Appointment Updated Successfully\n ";
                return ;
            }}
            cout<<"Invalid Id Entered ! \n";
    }

    void deleteAppointment(){
        int id;
        cout<<"Enter Appointment Id: ";
        cin>>id;
        for(int i=0;i<appointments.size();i++){
            if(appointments[i].getId()==id){
              appointments.erase(appointments.begin()+i);
                cout<<"Appointment Deleted Successfully !\n";
                return ;
            }
        }
            cout<<"Invalid Appointment Id !\n";
    }

    void generateBill(){
        int P_Id;
        cout<<"Enter Patient Id: ";
        cin>>P_Id;
        if(!patientExist(P_Id)){
        cout<<"Invalid Patient Id ! ";
        return ;
    }
    else{
    int d_fee,Test_fee,M_fee;
    cout<<"Enter Doctor fee: ";
    cin>>d_fee;
    cout<<"Enter Test fee: ";
    cin>>Test_fee;
    cout<<"Enter Medicines fee: ";
    cin>>M_fee;
    Billing<int> b(P_Id,d_fee,Test_fee,M_fee);
    Show_BillSummary(b);
}}
    };
    
    int main(){
    HospitalSystem H;
    H.loadAll();
    int choice=0;
    while(choice!=6){
    cout<<"\n______ Hospital Management System _______\n\n";
    cout<<"1. Patient Management \n";
    cout<<"2. Doctor Management\n";
    cout<<"3. Medicines\n";
    cout<<"4. Appointments\n";
    cout<<"5. Billing Payments\n";
    cout<<"6. Exit !\n";
        
    cout<<"\nEnter choice: ";
    cin>>choice;
    if(choice==1){
    int p=0;
    while(p<1 || p>4){
    cout<<"\n1. Add Patients:\n2. View Patients:\n3. Update Patient:\n4. Delete Patient:\n Enter choice: ";
    cin>>p;
    switch(p){
    case 1:
     H.addPatient();
    break;
    case 2:
     H.viewPatients(); 
    break;
    case 3:
     H.updatePatient(); 
    break;
    case 4:
    H.deletePatient(); 
    break;
    default:
    cout<<"\n Invalid Input Try Again \n ";
    }
    }
    }
    else if(choice==2){
             int d=0;
    while(d<1 || d>4){
    cout<<"\n1. Add Doctors:\n2. View Doctors:\n3. Update Doctor:\n4. Delete Doctor:\n\n Enter choice: ";
    cin>>d;
    switch(d){
    case 1:
    H.addDoctor();
    break;
    case 2:
    H.viewDoctors();
    break;
    case 3:
    H.updateDoctor();
    break;
    case 4:
    H.deleteDoctor();
    break;
    default:
    cout<<"\n Invalid Input Try Again \n";
        }}}
    else if(choice == 3) {
    int m=0;
    while(m<1 || m>2){
    cout<<"\n1. Add Medicines: \n2. View Medicines:\n\n Enter choice: ";
    cin>>m;
    switch(m){
    case 1:
    H.addMedicine();
    break;
    case 2: 
    H.viewMedicines();
    break;
    default:
    cout<<" \n Invalid Input Try Again \n ";
        }}}
    else if(choice == 4) {
    int a=0;
    while(a<1 || a>4){
    cout<<"\n1. Book Appointment:\n2. View Appointments:\n3. Update Appointment:\n4. Delete Appointment: \n\n Enter choice: ";
    cin>>a;
    switch(a){
    case 1:
    H.bookAppointment();
    break;
    case 2:
    H.viewAppointments();
    break;
    case 3:
    H.updateAppointment();
    break;
    case 4:
    H.deleteAppointment();
    break;
    default:
    cout<<" \n Invalid Input Try Again \n ";
        }}}
    else if(choice == 5) {
    H.generateBill();
       }
    else if(choice == 6) {
    cout<<"Exit ! \n\n";
        }
    else {
    cout<<"Invalid choice !\n";
        }
    }
    H.saveAll();
}
