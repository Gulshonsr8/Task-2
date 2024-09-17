#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string getResponse(string userInput) {
    // Convert the input to lowercase to make the bot case insensitive
    userInput = toLowerCase(userInput);

    if (userInput.find("hello") != string::npos || userInput.find("hi") != string::npos) {
        return "Hello! How can I assist you today?";
    } else if (userInput.find("how are you") != string::npos) {
        return "I'm just a bot, but I'm functioning as expected!";
    } else if (userInput.find("name") != string::npos) {
        return "I'm ChatBot, your virtual assistant.";
    } else if (userInput.find("bye") != string::npos || userInput.find("exit") != string::npos) {
        return "Goodbye! Have a great day!";
    } else {
        return "I'm not sure how to respond to that. Could you please clarify?";
    }
}

int main() {
    string userInput;
    cout << "ChatBot: Hello! I am a simple chatbot. Type 'exit' to end the conversation." << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        // Check if the user wants to exit the chat
        if (toLowerCase(userInput).find("exit") != string::npos) {
            cout << "ChatBot: Goodbye!" << endl;
            break;
        }

        // Get the chatbot's response
        string response = getResponse(userInput);
        cout << "ChatBot: " << response << endl;
    }

    return 0;
}