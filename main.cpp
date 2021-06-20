#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string exec(string command);

string convertToString(char *a);

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "invalid format\n";

    return 0;
  }

  const string taget_file_path = argv[2];
  ifstream target_hash_file(taget_file_path);
  istreambuf_iterator<char> it(target_hash_file), end;

  const string target_hash(it, end);

  const string file_path = argv[1];
  const string base_command = "shasum -a 256 ";
  const string command = base_command + file_path;

  const string hash = exec(command);

  if (hash == target_hash)
    cout << "the file is correct" << endl;
  else
    cout << "the file is corrupted" << endl;
  return 0;
}

string exec(string command) {
  char buffer[128];
  string result;

  FILE *pipe = popen(command.data(), "r");

  if (!pipe) {
    return "popen failed!";
  }

  // read till end of process:
  while (!feof(pipe)) {

    // use buffer to read and add to result
    if (fgets(buffer, 128, pipe) != NULL)
      result += buffer;
  }

  pclose(pipe);

  return result;
}
