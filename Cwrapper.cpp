#include <Python.h>
#include <iostream>
using namespace std;

class Cwrapper{
    public:
    void initializeCluster(){
        const char* filename = "ClusterManager.py";

        //TODO
        // initialize the interpreter
        Py_Initialize();
        
        //get file handle FROM THE PYTHON LIBRARY else it can crash due to improper file handle implementation
        PyObject *obj = Py_BuildValue("s", filename);
        FILE *fname = _Py_fopen_obj(obj, "r+");

        //load the file into the interpreter
        PyRun_SimpleFile(fname, filename);
    }

    void shutdownCluster(){
        //TODO
        // shut down the interpreter and release (most?) resources
        Py_Finalize();
    }

    void submit(){
        //TODO
    }

    void eval(const char* command){
        PyRun_SimpleString(command);
    }
};

int main(){
    Cwrapper wrap;
    wrap.initializeCluster();
    string command;
    getline(cin, command);
    wrap.eval(command.c_str());
    wrap.shutdownCluster();
    return 0;
}