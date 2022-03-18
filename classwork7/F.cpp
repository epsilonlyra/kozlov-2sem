#include<iostream>
using namespace std;
enum Status {Continue = 100, OK = 200, Created = 201, Accepted = 202, BadRequest = 400, Unauthorized = 401, \
                NotFound = 404, MethodNotAllowed = 405, InternalServerError = 500, NotImplemented = 501, BadGateway = 502};

void Declaremistake(int N){
    switch(N)
    {
    case Continue:
        cout << "Continue";
        break;
    case OK:
        cout << "OK";
        break;
    case Created:
        cout << "Created";
        break;
    case Accepted:
        cout << "Accepted";
        break;
    case BadRequest:
        cout << "Bad Request";
        break;
    case Unauthorized:
        cout << "Unauthorized";
        break;
    case NotFound:
        cout << "Not Found";
        break;
    case MethodNotAllowed:
        cout << "Method Not Allowed";
        break;
    case InternalServerError:
        cout << "Internal Server Error";
        break;
    case NotImplemented:
        cout << "Not Implemented";
        break;
    case BadGateway:
        cout << "Bad Gateway";
        break;
    }
}

int main(){

int Requests[1000];

int i = 0;
while (true){

    int temp;
    cin >> temp;

    if (temp == 0){
        break;
    }

    Requests[i] = temp;
    i += 1;
}

for (int j = 0; j < i; j++){
    Declaremistake(Requests[j]);
    cout << endl;
}

return 0;
}
