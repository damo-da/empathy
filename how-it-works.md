---
layout: page
---

Yo! Straight to the topic of how the core of Empathy works like.

First, there is an object canned `You`. The name `Empathy` comes in direct relation to `You`. As anyone uses Empathy, he/she can scream at the app: "`You` made me feel better!"

Then there are brains. You know how humans have two hemispheres of brain that perform different tasks? Yeah, well, Empathy has too(except it can hold any number of `Brain`s)! Each `Brain` is meant to do one particular stuff, like, one `Brain` handles all life events in the screen and another `Brain` might be analysing how the user reacts. And when two `Brain`s need to intercommunicate, they emit and listen to `Event`s.

Now, let's get down to the stuffs that appear on the screen. They're called `LifeEvent`s because they are meant to come and go in `Life`. Each LifeEvent is \[meant to be\] created by `You` and `You` is controlled by `Brain`s. Each `LifeEvent` have `onCreate()`, `onRun()`, `onFinish()` and an `onDestroy()` method which can be overidden to serve your needs. Let's consider a flower moving away in screen. During the `onCreate()` phase, make it fade in, and `onRun()` phase, calculate its movement and during the `onFinish()` phase, make it fade out, it's that simple!

Do you remember asynchronous timed events in JavaScript: `setInterval(fun)` and `setTimeout(fun)`? Yeah, well they are here too! But a little complex. Check out the docs!
