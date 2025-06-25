#include <iostream>
#include <string>

using namespace std;

// Базовий клас
class Notification {
protected:
    string title;
    string text;

public:
    Notification(const string& t, const string& txt)
        : title(t), text(txt) {}

    virtual void show() const {
        cout << "Zagolovok: " << title << endl;
        cout << "Tekst: " << text << endl;
    }

    virtual ~Notification() {} 
};

// Похідний клас
class ImportantNotification : public Notification {
private:
    string priority; 
    void (*extraAction)();

public:
    ImportantNotification(const string& t, const string& txt, const string& p)
        : Notification(t, txt), priority(p), extraAction(0) {}

    void setExtraAction(void (*action)()) {
        extraAction = action;
    }

    void show() const {
        Notification::show();
        cout << "Riven vazhlyvosti: " << priority << endl;

        if (priority == "vysokyy" && extraAction) {
            extraAction();
        }
    }
};

void confirmationMessage() {
    cout << "Potribne pidtverdzhennya!" << endl;
}

int main() {
    ImportantNotification notif("Uvaha!", "Tse duzhe vazhlyve povidomlennya.", "vysokyy");

    //  додаткова дія
    notif.setExtraAction(&confirmationMessage);

    notif.show();

    return 0;
}

