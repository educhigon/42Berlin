package com.example.calculator

import android.os.Bundle
import android.util.Log
import android.util.Log.i
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.gestures.snapping.SnapPosition
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.BoxWithConstraints
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.heightIn
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
import androidx.compose.material3.TextButton
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalDensity
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
                        modifier = Modifier
                            .fillMaxSize()
                            .padding(innerPadding),
                        verticalArrangement = Arrangement.SpaceBetween
                    ) {
                        ResultFields(
                            modifier = Modifier
//                                .fillMaxSize()
                                .fillMaxWidth()
                                .weight(4f)
                        )
                        Keypad(
                            modifier = Modifier
//                                .fillMaxSize()
                                .fillMaxWidth()
                                .weight(6f)
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
fun ResultFields(modifier: Modifier = Modifier) {

    Column (
        modifier = modifier
            .fillMaxSize()
            .padding(8.dp),
        verticalArrangement = Arrangement.SpaceEvenly
    ) {
        Text(
            text = "0x0",
//            maxLines = 10,
            fontSize = 50.sp,
            textAlign = TextAlign.End,
            modifier = Modifier.align(Alignment.End)
                .fillMaxWidth()
        )

        Text(
            text = "00000",
//            maxLines = 10,
            fontSize = 50.sp,
            textAlign = TextAlign.End,
            modifier = Modifier.align(Alignment.End)
                .fillMaxWidth()
        )
    }

}
@Composable
fun Keypad(modifier: Modifier = Modifier) {

    val buttons1 = listOf("7", "8", "9", "C", "AC")
    val buttons2 = listOf("4", "5", "6", "+", "-")
    val buttons3 = listOf("1", "2", "3", "*", "/")
    val buttons4 = listOf("0", ".", "00", "=", "")
    val buttons = listOf(buttons1, buttons2, buttons3, buttons4)

    Column(
        modifier = modifier
            .fillMaxSize()
    ) {
        buttons.forEach {
            Row(modifier = Modifier
                .fillMaxSize()
                .weight(1f),
                horizontalArrangement = Arrangement.Center
            ) {
                it.forEach { label ->
                    val textColor = when (label) {
                        "AC", "C" -> Color.Red
                        "+", "-", "*", "/" -> Color.White
                        else -> Color.Gray
                    }
                    TextButton(onClick = {Log.d("TAG", "Button $label clicked")},
                        modifier = modifier
                            .fillMaxSize()
                            .weight(1f)
                    ) {
                        Text(
                            text = label,
                            fontSize = 30.sp,
                            color = textColor
                        )
                    }
                }
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
                    modifier = Modifier.fillMaxSize().padding(innerPadding)
                )
                Keypad(
                    modifier = Modifier.padding(innerPadding)
                )
            }
        }
    }
}