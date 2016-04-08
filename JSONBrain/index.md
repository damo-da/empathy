---
layout: page
title: JSONBrain
---

# JSON Brain

So you wanna make your `Brain` as easily as you want? Here's `JSONBrain`, a way to create Brain using simple rules in a JSON file. So, let's get started!

The rules are pretty simple: 
Create a simple JSON like this:

```
{
	"title":"My custom JSON",
	"version":0.0,
	"fileAuthor":"Mr. Robot",
	"copyright":"Public Domain",
	"steps":{}
}

```

I believe that everything except the `steps` are self-explanatory. The steps are the command instructions that you give to your program. They follow a strict rule represented by a simple `"key" : "array_value"` structure. A sample data goes like this:

```
{
"steps":{
	"code_1":[
		--instruction_1--
		--instruction_2--
	],
	"code_2":[
		--instruction_3--
		--instruction_4--
		--instruction_5--
	]
	
}
}
```

To understand the role of code and action, here's a particular thing to understand regarding Empathy: it's event driven. In this examples, the events are registered as "code_1" and "code_2", and the instrutions to be launched at the respective events are kept as it's array type. For example, You need to create a wave on beginning of a program. You might need to do this:

```
{
"steps":{
	"begin":[
		{"type":"create",create":"wave","frequency":0.2,"wavelength":0.4}
	]
}
}
```

----
To timeout your event , you need a `"type"="goto"` instruction.

```
{"type":"goto","stepID":"create_wave_1","in":0.5}
```
What this instruction does is, it executes action `create_wave_1` in 0.5 seconds. If you want to modularize your code, you might want to create a lot of custom actions, and just create `goto` actions in your execution flow. 

Now, here is the full list of JSON syntaxes.


---
So here we pretty much summed up how JSONBrain parses JSON files. 


