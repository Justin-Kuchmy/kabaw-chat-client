# Kabaw Chat Client
A simple WebSocket chat client built in Qt (C++) using the [kabaw-sockets](https://github.com/kabaw-ai/kabaw-sockets) backend.

---

## Project Structure
kabaw-chat-client/ <br>
├── README.md <br>
├── LICENSE <br>
├── .gitignore <br>
├── Include # c++ header files <br>
├── src # Qt/C++ source files <br>
├── build/ # CMake build directory <br>
└── screenshots/ # Progress images <br>

# Progress / Screenshots

| Step | Screenshot | Description |
|------|-----------|-------------|
| 1    | ![Empty Window](screenshots/screenshot01-mainwindow.png) | Minimal Qt window opens |
| 2    | ![Empty Window](screenshots/screenshot02-menubar.png) | menu bar with working exit button |
| 3    | ![Empty Window](screenshots/screenshot03-simplehtmlclient.png) | simple html client page |
| 4    | ![Empty Window](screenshots/screenshot04-2connections.png) | two connections sending messages |
| 5    | ![Empty Window](screenshots/screenshot05-chatroomui.png) | ui for chatroom and join dialog box |
| 6    | ![Empty Window](screenshots/screenshot06-qwebsockettest.png) | receving messages from server via QWebSocket |
| 7    | ![Empty Window](screenshots/screenshot07-receivedmessages.png) | Left: Connects to WebSocket server with username, channel and sets up connection, waiting for received messages.emits messageReceived when we get a message from the server. json messages from server are parsed into a custom Message Object. <br> <br> Right: set up the connection listen for the emitted signal, then we pass the message to addMessageToList and calling parseMessage before displaying it on the UI |
| 8    | ![Empty Window](screenshots/screenshot8-twoclients.png) | Simply two clients both connected to the same channel, both in communication|
| 9    | ![Empty Window](screenshots/screenshot09-addedsomestyles.png) | Personal Messages show up brighter and on the right side only, added css for the qlistwidget and items. Visited channels will be saved and rejoined with just a click |
| 10    | ![Empty Window](screenshots/screenshot10-linux-pc.png) | My Linux laptop connected via my private static ip address |
| 11    | ![Empty Window](screenshots/screenshot11-windows-pc.png) | My Windows laptop connected to the same private static ip address on the same network |
<br>
> More updates will be added as development progresses.

---

## Installation & Running

### Prerequisites

- C++ compiler  
  - **Windows:** g++ via MSYS2 (MinGW)
  - **Linux:** g++ or clang
- CMake
- Qt6
- PowerShell (Windows) or Bash (Linux)
- Web browser (for WebSocket test pages)

---

## Windows

```powershell
# Clone the repository
git clone https://github.com/Justin-Kuchmy/kabaw-chat-client.git
cd kabaw-chat-client

# Configure the project
cmake -S . -B build -G "MinGW Makefiles"

# Build the project
cmake --build build

# Run the executable
cd build; ./Kabaw_chat_client.exe
```
--
## Linux
--

```bash
# Clone the repository
git clone https://github.com/Justin-Kuchmy/kabaw-chat-client.git
cd kabaw-chat-client

# Configure and build the project (may need to adjust path)
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu
cmake --build build -j$(nproc)

# Run the executable
cd build
./Kabaw_chat_client

#If the executable is not runnable:
chmod +x build/Kabaw_chat_client

```

##Server

This project is a client for the Kabaw WebSocket server.

Server setup and instructions can be found here:
👉 <https://github.com/kabaw-ai/kabaw-sockets>

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
