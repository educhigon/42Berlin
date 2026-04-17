The 5 rules that cover 90% of layout problems

### Rule 1: Parent controls placement, children control size
>> kotlin// Parent decides WHERE children go
Column(verticalArrangement = Arrangement.SpaceBetween) { }
Row(horizontalArrangement = Arrangement.SpaceEvenly) { }

// Children decide HOW BIG they are
Text(modifier = Modifier.fillMaxWidth())
Button(modifier = Modifier.weight(1f))

### Rule 2: weight is your most important tool
>> kotlin// Equal space - use same weight
Column {
    Box(modifier = Modifier.weight(1f)) { } // half
    Box(modifier = Modifier.weight(1f)) { } // half
}

// Proportional space
Column {
    Box(modifier = Modifier.weight(2f)) { } // 2/3
    Box(modifier = Modifier.weight(1f)) { } // 1/3
}

### Rule 3: fillMaxSize/Width/Height only works if parent has size
>> kotlin// This works - parent has size
Column(modifier = Modifier.fillMaxSize()) {
    Text(modifier = Modifier.fillMaxWidth()) // parent has width, this works
}

// This breaks - parent has no size
Column {
    Text(modifier = Modifier.fillMaxWidth()) // parent has no width, ignored
}

### Rule 4: modifier order matters, innerPadding applied once
>> kotlin// Correct
Column(
    modifier = Modifier
        .fillMaxSize()
        .padding(innerPadding) // system bars
        .padding(16.dp)        // your spacing
)
// Never pass innerPadding to children - it doubles the padding

### Rule 5: which tool for which job
Column     → stack vertically
Row        → stack horizontally  
Box        → overlap / wrap a single element
Scaffold   → screen with topBar/bottomBar
Spacer     → empty space between elements

### Modifier cheatsheet

>> ROWs + COLUMNs + BOXes:
https://proandroiddev.com/cheatsheet-for-centering-items-in-jetpack-compose-1e3534415237

>> How to Build a BottomNavBar
https://medium.com/@jpmtech/jetpack-compose-bottom-navigation-bar-3e1e8749fb2c

>> Create your first AndroidApp
https://developer.android.com/codelabs/basic-android-kotlin-compose-first-app#0



>> kotlin// SIZE
Modifier.fillMaxSize()          // fill all available space
Modifier.fillMaxWidth()         // fill width only
Modifier.fillMaxHeight()        // fill height only
Modifier.weight(1f)             // share available space proportionally
Modifier.size(48.dp)            // fixed width AND height
Modifier.width(100.dp)          // fixed width
Modifier.height(48.dp)          // fixed height

>> // SPACING
Modifier.padding(16.dp)         // all sides
Modifier.padding(horizontal = 16.dp, vertical = 8.dp)
Modifier.padding(top = 8.dp)    // one side only

>> // ALIGNMENT (only works inside Box)
Modifier.align(Alignment.Center)
Modifier.align(Alignment.TopEnd)
Modifier.align(Alignment.BottomStart)

>> Alignment cheatsheet
>> kotlin// On Column - affects ALL children horizontally
Column(horizontalAlignment = Alignment.CenterHorizontally)
Column(horizontalAlignment = Alignment.Start)
Column(horizontalAlignment = Alignment.End)

>> // On Row - affects ALL children vertically  
Row(verticalAlignment = Alignment.CenterVertically)
Row(verticalAlignment = Alignment.Top)
Row(verticalAlignment = Alignment.Bottom)

>> // On Box - per child, use Modifier.align()
Box {
    Text(modifier = Modifier.align(Alignment.Center))
    Text(modifier = Modifier.align(Alignment.BottomEnd))
}

>> // On Text - aligns text WITHIN its own bounds
Text(textAlign = TextAlign.End)    // needs fillMaxWidth to be visible
Text(textAlign = TextAlign.Center)


The 3 questions to ask yourself when layout breaks

Does my parent have a size? If parent has no size, fillMax on children does nothing.
Where am I applying innerPadding? Should be exactly once, on outermost element.
Am I using weight inside a sized parent? weight only works if parent has fillMaxSize/Height/Width.


The debugging move when nothing works
Add a colored background to see exactly what space each element occupies:
kotlinText(
    text = "hello",
    modifier = Modifier
        .background(Color.Red)   // see exactly how big this is
        .fillMaxWidth()
)

Column(
    modifier = Modifier
        .background(Color.Blue)  // see exactly how big this is
        .fillMaxSize()
)
This tells you immediately whether your element has the size you think it has.

The mental checklist before writing any layout
Draw it on paper first. Label each element as Column, Row, or Box. Ask:

Which elements share a row? → wrap in Row
Which elements stack vertically? → wrap in Column
Does anything overlap? → use Box
Who gets equal space? → give them equal weight

Then translate directly to code. Don't adjust as you go — get the structure right first, then add styling.
