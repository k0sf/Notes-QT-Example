This is the `qwebchannel.js` file exactly as it is from the Qt WebChannel repository, uploaded to NPM for convenience.

***Note**: not an official Digia upload, this is a community-maintained package*

# Official description

The QWebChannel fills the gap between C++ applications and HTML/JavaScript applications. By publishing a QObject derived object to a QWebChannel and using the qwebchannel.js on the HTML side, one can transparently access properties and public slots and methods of the QObject. No manual message passing and serialization of data is required, property updates and signal emission on the C++ side get automatically transmitted to the potentially remotely running HTML clients. On the client side, a JavaScript object will be created for any published C++ QObject. It mirrors the C++ object's API and thus is intuitively useable.

The C++ QWebChannel API makes it possible to talk to any HTML client, which could run on a local or even remote machine. The only limitation is that the HTML client supports the JavaScript features used by qwebchannel.js. As such, one can interact with basically any modern HTML browser or standalone JavaScript runtime, such as node.js.


You can take the JS file and use it in the browser with a `<script />` tag or via Browserify/Webpack, or from node using `require('qwebchannel')`. From this, you can interact your Qt 5 or PySide 2-based application from a WebEngine view or a Node script.

Assorted links/reading material:

 * http://code.qt.io/cgit/qt/qtwebchannel.git/ (official Git repo)
 * https://github.com/qtproject/qtwebchannel (GitHub mirror)
 * http://doc.qt.io/qt-5/qtwebchannel-index.html
 * https://www.kdab.com/qt-webchannel-bridging-gap-cqml-web/
 * https://www.qtdeveloperdays.com/sites/default/files/webchannel.pdf