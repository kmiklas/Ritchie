# Usage
## Engine/Acceptor
The Ritchie engine is designed to run on Linux, but it should run on Windows with a few tweaks if you're a Visual Studio person.

At the command prompt:
pickledEgg> make

To start the process and make your market
pickledEgg> ./ritchie

## Client/Initiator

Separate clients are available: one for Linux/Mac, a second for Windows.

Portability was just too difficult to maintain with the vast difference between Linux/UNIX/Mac socket implementations and Winsock2.h. Forgive me for throwing in the towel and let the split occur, so that Visual Studio can do its thing with the Windows version of the initiator. Every man has his limit, and reached mine.


# Change Log
4/24/2017
- Added order priority queue (modified heap) stub for holding order info at price levels in order book
- Added order number generater

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

