package com.example.calculator

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Grid
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.material3.Button
import androidx.compose.material3.CenterAlignedTopAppBar
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.ParagraphStyle
import androidx.compose.ui.text.buildAnnotatedString
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.text.withStyle
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.calculator.ui.theme.CalculatorTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            CalculatorTheme {
                Scaffold(
                    modifier = Modifier.fillMaxSize(),
                    topBar = { TopAppBar() }  // ← belongs here
                ) { innerPadding ->
                    Column (
                        modifier = Modifier.fillMaxHeight().padding(16.dp),
                        verticalArrangement = Arrangement.Bottom
                    ) {
                        ResultFields(
                            name = "text",
                            modifier = Modifier.fillMaxSize().padding(innerPadding),
                        )
                        Keypad(
                            name = "text",
                            modifier = Modifier.padding(innerPadding)
                        )
                    }
                }
            }
        }
    }
}


@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TopAppBar() {
    CenterAlignedTopAppBar(
        colors = TopAppBarDefaults.topAppBarColors(
            containerColor = MaterialTheme.colorScheme.primaryContainer,
            titleContentColor = MaterialTheme.colorScheme.primary,
        ),
        title = {
            Text(
                "Calculator",
                maxLines = 1,
                overflow = TextOverflow.Ellipsis
            )
        }
    )
}

@Composable
fun ResultFields(name: String, modifier: Modifier = Modifier) {


    Text(
        buildAnnotatedString {
            withStyle(style = ParagraphStyle(lineHeight = 100.sp)) {
                append("0x0")
            }
        },
        maxLines = 10,
        fontSize = 50.sp,
        overflow = TextOverflow.Ellipsis,
        textAlign = TextAlign.Right,
        modifier = Modifier.width(800.dp)
    )

    Text(
        buildAnnotatedString {
            withStyle(style = ParagraphStyle(lineHeight = 100.sp)) {
                append("00000")
            }
        },
        maxLines = 10,
        fontSize = 50.sp,
        overflow = TextOverflow.Ellipsis,
        textAlign = TextAlign.Right,
        modifier = Modifier.width(800.dp)
    )
}
@Composable
fun Keypad(name: String, modifier: Modifier = Modifier) {

    val buttons = listOf(
        "7", "8", "9", "C", "AC",
        "4", "5", "6", "+", "-",
        "1", "2", "3", "*", "/",
        "0", ".", "00", "=", ""
    )

    LazyVerticalGrid(
        columns = GridCells.Fixed(5)  // 5 columns
    ) {
        items(buttons.size)   { i ->
            Button(onClick = {
//                println("Button "); println(buttons.elementAt(i)); println(" clicked")
                Log.d("TAG", "Button ${buttons[i]} clicked")   // prints to Android Logcat
            }) {
                Text(
                    text = buttons[i],
                    fontSize = 20.sp,
                    modifier = modifier
                )
            }
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    CalculatorTheme{
        Scaffold(
            modifier = Modifier.fillMaxSize(),
            topBar = { TopAppBar() }  // ← belongs here
        ) { innerPadding ->
            Column (
                modifier = Modifier.fillMaxHeight().padding(16.dp),
                verticalArrangement = Arrangement.Bottom
            ) {
                ResultFields(
                    name = "text",
                    modifier = Modifier.fillMaxSize().padding(innerPadding),
                )
                Keypad(
                    name = "text",
                    modifier = Modifier.padding(innerPadding)
                )
            }
        }
    }
}