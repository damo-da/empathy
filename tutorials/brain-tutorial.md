---
layout: page
title: Brain 101
---

# Make-your-own-`Brain` tutorial

`Brain`s provide logic for displaying `LifeEvent`s around the screen. If you want to create a handle for your stuffs, say to go to edge of the universe, you extend the base `empathy::brain::Brain` class. Like this:

`class RocketBrain : public Brain;`

This class **MUST** override a method named runLineNumber. you do this by: 

`public void runLineNumber(String action, String caller);`

Now, you have to understand HOW Brain works to understand what this statement is. The Brain is started by `You` and as it begins running, it starts asynchronous timeouts to create `LifeEvent`s. Say, you want to build a wave of red color and a wave of blue color immediately afterwards. Your implementationn should be like:

onStart: wave1
after 3 seconds: wave2 (for simplicity, say the wave completes in 3 seconds)

The use of `runLineNumber` is to execute a certain statement and create the intruction for timeouts. Your runLineNumber needs to be like:

{% highlight c++ %}
public void runLineNumber(std::string action, std::string caller="")
{
	if(action=="begin"){
	        activateTimeoutForNextLine("createWave1",0.0);//go to createWave1 after 0.0 secconds, ie, immediately
	}else if(action=="createWave1"){
		createWave1();//your code to create a wave

	        activateTimeoutForNextLine("createWave2",3.0);//go to createWave2 after 3.0 seconds
	}else if(action=="createWave2"){
		createWave2(); //your code to create another wave.
		
		//And if you want an infinite loop, You can call this line
		activateTimeoutForNextLine("begin",3.0);//restart after 3.0 seconds
	}
}
{% endhighlight %}

You might have noticed action=="begin" on line 3. This comes from `You` after empathy has finished instanciating.




The following code block WILL be syntax-highlighted.

## A class
{% highlight c++ %}
namespace transport
{
	/* Standard bicycle class.
	 *
	 * Bicycle implements a standard bicycle. Bicycles are a useful way of
	 * transporting oneself, without too much effort (unless you go uphill
	 * or against the wind). If there are a lot of people on the road, you
	 * can use <RingBell> to ring your bell (**note**, not all bicycles
	 * have bells!).
	 */
	class Bicycle
	{
	public:
		// PedalHarder makes you go faster (usually).
		virtual void PedalHarder();

		/* Ring bell on the bike.
		 *
		 * RingBell rings the bell on the bike. Note that not all
		 * bikes have bells. */
		virtual void RingBell();

		// Default destructor.
		virtual ~Bicycle();
	};
}
{% endhighlight %}
