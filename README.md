# Ritchie - The Open Source Exchange

![Ritchie Logo](http://www.ritchiestockexchange.com/img/logo.png)

http://www.ritchiestockexchange.com/


![Ritchie Logo](https://www.gnu.org/graphics/gplv3-127x51.png)

https://www.gnu.org/licenses/gpl-3.0.en.html

https://opensource.com/open-source-way

# Communication

Register and post at the Ritchie forums:

http://www.ritchiestockexchange.net/

Huge thanks to myBB for this.

![myBB Logo](https://mybb.com/assets/images/logo.png)

https://mybb.com/

# Contribute

Current needs:

1. ENGINE: Creating the order book of priority queues (heaps), bid/ask price ladders, matching engine, and the like
2. FIX ACCEPTOR/INITIATOR: Creating a FIX connection between a client and the exchange. I've been working with a modified version of Quickfix, but I would really prefer to write our own FIX engine.
3. SOCKET PROGRAMMING. The model calls for users to remote into their colo equipment and run their algos remotely. This is great, because network latency becomes a non-factor. Yes, connection from your basement fund to the Ritchie colo equipment might be slow, but your algo is on the same LAN as everyone else. Once you modify, update, and run your algo, a C++ socket connection directly to the market acceptor enables you to trade at the same speeds as everyone else.  I haven't timed it, but I'm looking for less than 500mcs market access times. Lots more on this...
4. SSL/SSH/Firewall. I suppose we need some form of security.
5. ALGOS. Algos to drive and test the market engine.
6. OTHER STUFF. Web-based data-driven portal to view market info, market data server, compliance logging, etc.


# Usage
## Engine/Acceptor
The Ritchie engine is designed to run on Linux, but it should run on Windows with a few tweaks if you're a Visual Studio person.

At the command prompt:
pickledEgg> make

To start the process and make your market
pickledEgg> ./ritchie

## Client/Initiator

Separate clients are available: one for Linux/Mac, a second for Windows. This enables the Windows peeps to work with the code in Visual Studio, generate solution files and all sorts of Microsoft-specific stuff, use winsock2.h, etc., without cluttering the Linux files.

I know, in a perfect world, this code would be perfectly portable, and we would have exactly one code base for all platforms. Please don't judge me.


# Change Log

4/25/2017
- nix: added socket stubs for initiator and acceptor
- Windows: added VS2015 project with socket stubs for initiator and acceptor

4/24/2017
- Engine: Added order priority queue (modified heap) stub for holding order info at price levels in order book. Added order number generator.

3/1/2017
- Initial commit

# Ritchie

Welcome to the Ritchie Stock Exchange™!

"Ritchie" is an Alternative Trading System (ATS) that is created, built, run, and managed by the open-source community.

In the spirit of "The Open Source Way,"[2] we believe that a market--and its data--must be free, open, and transparent to be "fair and orderly:"

- Designed for Algorithmic Trading.
- No "non-display" fees. Ritchie is designed from the ground up for non-display.
- Affordable colocation fees. Colocation is affordable at Ritchie. Your algos can be run on a device as small as a Raspberry Pi(TM).
- Random matching algorithm. Not a FIFO order queue, an array where orders are matched randomly.
- Real-time tick data are free. Easily accessed through our API.
- Open Order Book/DOM.
- Open API. Designed for algorithmic trading and quantitative analysis.
- Open Architecture. The inner workings of the exchange are open for public scrutiny.
- Open Order Arrays.
- Free FIX adapter
- Open Source!

Check out our Web presence at the following three sites:

http://www.ritchiestockexchange.com/ is a window into the exchange.<br>
http://www.ritchiestockexchange.net/ are the forums.<br>
http://www.ritchiestockexchange.org/ is the governing and documentation site.<br>
<br>
Sincerely,
Keith :^)

![Ritchie Affordable Colocation](http://www.ritchiestockexchange.org/img/colocateRitchie2.jpg)


Reference:
1. https://opensource.com/open-source-way

