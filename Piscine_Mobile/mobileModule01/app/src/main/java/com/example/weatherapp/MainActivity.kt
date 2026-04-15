package com.example.weatherapp

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.gestures.snapping.SnapPosition
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.statusBarsPadding
import androidx.compose.foundation.pager.HorizontalPager
import androidx.compose.foundation.pager.PagerState
import androidx.compose.foundation.pager.rememberPagerState
import androidx.compose.foundation.text.KeyboardActions
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.foundation.text.input.TextFieldState
import androidx.compose.material3.Badge
import androidx.compose.material3.BadgedBox
import androidx.compose.material3.CenterAlignedTopAppBar
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.NavigationBar
import androidx.compose.material3.NavigationBarItem
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.sp
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewmodel.compose.viewModel
import com.example.weatherapp.ui.theme.WeatherAppTheme
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.CalendarViewWeek
import androidx.compose.material.icons.filled.Timer
import androidx.compose.material.icons.filled.Today
import androidx.compose.material.icons.outlined.CalendarViewWeek
import androidx.compose.material.icons.outlined.Navigation
import androidx.compose.material.icons.outlined.Timer
import androidx.compose.material.icons.outlined.Today
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.SearchBar
import androidx.compose.material3.SearchBarDefaults
import androidx.compose.material3.Surface
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.ui.Alignment
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.graphicsLayer
import androidx.compose.ui.text.input.ImeAction
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.launch

data class TabBarItem(
    val title: String,
    val selectedIcon: ImageVector,
    val unselectedIcon: ImageVector,
    val badgeAmount: Int? = null
)

class WeatherViewModel() : ViewModel() {

    val currentlyTab = TabBarItem(title = "Currently", selectedIcon = Icons.Filled.Timer, unselectedIcon = Icons.Outlined.Timer)
    val todayTab = TabBarItem(title = "Today", selectedIcon = Icons.Filled.Today, unselectedIcon = Icons.Outlined.Today)
    val weeklyTab = TabBarItem(title = "Weekly", selectedIcon = Icons.Filled.CalendarViewWeek, unselectedIcon = Icons.Outlined.CalendarViewWeek)

    // creating a list of all the tabs
    val tabBarItems = listOf(currentlyTab, todayTab, weeklyTab)
    var searchResult by mutableStateOf("")
        private set
    fun set_SearchResult(value: String) { searchResult = value }

}


class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            WeatherAppTheme {
                val viewModel: WeatherViewModel = viewModel()
                val pagerState = rememberPagerState(pageCount = { viewModel.tabBarItems.size })

                Scaffold(
                    topBar = { TopAppBar(viewModel) },
                    bottomBar = { BottomNavBar(viewModel.tabBarItems, pagerState) }
                ) { innerPadding ->
                    HorizontalPager(modifier = Modifier
                        .fillMaxSize()
                        .padding(innerPadding),
                        state = pagerState
                    ) { pageIndex ->
                        when (pageIndex) {
                            0 -> CurrentlyScreen(viewModel)
                            1 -> TodayScreen(viewModel)
                            2 -> WeeklyScreen(viewModel)
                        }
                    }
                }
            }
        }
    }
}

@Composable
fun PrintName(title : String, subtitle: String?, modifier: Modifier = Modifier) {
    Column(
        modifier = modifier
            .fillMaxSize()
            .padding(8.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally // center children horizontally
    ) {
        Text(
            text = title,
            fontSize = 50.sp,
            textAlign = TextAlign.Center // center text inside its bounds
        )

        if (!subtitle.isNullOrBlank()) {
            Spacer(modifier = Modifier.height(8.dp))
            Text(
                text = subtitle,
                fontSize = 40.sp,
                textAlign = TextAlign.Center
            )
        }
    }
}
@Composable
fun CurrentlyScreen(viewModel: WeatherViewModel) {
    val title = "Currently"
    val subtitle = viewModel.searchResult.takeIf { it.isNotBlank() } // null if empty
    PrintName(title = title, subtitle = subtitle)
}
@Composable
fun TodayScreen(viewModel: WeatherViewModel) {
    val title = "Today"
    val subtitle = viewModel.searchResult.takeIf { it.isNotBlank() } // null if empty
    PrintName(title = title, subtitle = subtitle)
}
@Composable
fun WeeklyScreen(viewModel: WeatherViewModel) {
    val title = "Weekly"
    val subtitle = viewModel.searchResult.takeIf { it.isNotBlank() } // null if empty
    PrintName(title = title, subtitle = subtitle)
}


@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TopAppBar(viewModel: WeatherViewModel, modifier: Modifier = Modifier) {
    val query = remember { TextFieldState() }
    Surface(
        color = MaterialTheme.colorScheme.primaryContainer,
        tonalElevation = 4.dp
    ) {
        Row( modifier
            .fillMaxWidth()
            .statusBarsPadding()
            .padding(start = 8.dp, end = 8.dp),
            verticalAlignment = Alignment.CenterVertically,
            horizontalArrangement = Arrangement.SpaceAround
        ) {
            Box(
                modifier = modifier
                    .padding(8.dp)
                    .weight(9f),
//                    .background(Color.White),
                contentAlignment = Alignment.Center
            ) {
                SimpleSearchBar(
                    textFieldState = query,
                    onSearch = { searchText ->
                        viewModel.set_SearchResult(searchText)
                        Log.d("Search --> ", viewModel.searchResult)
                    },
                )
            }
            Box(
                modifier = modifier
                    .padding(8.dp)
                    .weight(2f)
//                    .background(Color.Red)
                    .clickable {viewModel.set_SearchResult("Geolocation")},
                contentAlignment = Alignment.Center,
            ) {
                Icon(
                    imageVector = Icons.Outlined.Navigation,
                    contentDescription = "Navigation",
                    modifier = Modifier.size(36.dp)
                        .graphicsLayer {
                            this.rotationX = 0f
                            this.rotationY = 0f
                            this.rotationZ = 45f
                        }
                )
            }
        }
    }
}

@Composable
fun BottomNavBar(tabBarItems: List<TabBarItem>, pagerState: PagerState) {

    val scope = rememberCoroutineScope()
    NavigationBar {
        // looping over each tab to generate the views and navigation for each item
        tabBarItems.forEachIndexed { index, tabBarItem ->
            NavigationBarItem(
                selected = pagerState.currentPage == index,
                onClick = {
                    scope.launch { pagerState.animateScrollToPage(index) }
                },
                icon = {
                    TabBarIconView(
                        isSelected = pagerState.currentPage == index,
                        selectedIcon = tabBarItem.selectedIcon,
                        unselectedIcon = tabBarItem.unselectedIcon,
                        title = tabBarItem.title,
                        badgeAmount = tabBarItem.badgeAmount
                    )
                },
                label = {Text(tabBarItem.title)})
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TabBarIconView(
    isSelected: Boolean,
    selectedIcon: ImageVector,
    unselectedIcon: ImageVector,
    title: String,
    badgeAmount: Int? = null
) {
    BadgedBox(badge = { TabBarBadgeView(badgeAmount) }) {
        Icon(
            imageVector = if (isSelected) {selectedIcon} else {unselectedIcon},
            contentDescription = title
        )
    }
}

@Composable
@OptIn(ExperimentalMaterial3Api::class)
fun TabBarBadgeView(count: Int? = null) {
    if (count != null) {
        Badge {
            Text(count.toString())
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun SimpleSearchBar(
    textFieldState: TextFieldState,
    onSearch: (String) -> Unit,
//    searchResults: List<String>,
    modifier: Modifier = Modifier
) {

    OutlinedTextField(
        value = textFieldState.text.toString(),
        onValueChange = { textFieldState.edit { replace(0, length, it) } },
        placeholder = { Text("Search location...") },
        singleLine = true,
        keyboardActions = KeyboardActions(
            onDone = { onSearch(textFieldState.text.toString()) }
        ),
        keyboardOptions = KeyboardOptions(
            imeAction = ImeAction.Done
        ),
        modifier = modifier.fillMaxWidth()
    )






    // Controls expansion state of the search bar
//    var expanded by rememberSaveable { mutableStateOf(false) }
//
//    SearchBar(
//        modifier = Modifier
//            .fillMaxWidth(),
//
////            .align(Alignment.TopCenter),
////                    .semantics { traversalIndex = 0f },
//        inputField = {
//            SearchBarDefaults.InputField(
//                query = textFieldState.text.toString(),
//                onQueryChange = { textFieldState.edit { replace(0, length, it) } },
//                onSearch = {
//                    onSearch(textFieldState.text.toString())
//                    expanded = false
//                },
//                expanded = expanded,
//                onExpandedChange = { expanded = it },
//                placeholder = { Text("Search") }
//            )
//        },
//        expanded = expanded,
//        onExpandedChange = { expanded = it },
//    ) {
//        Text(textFieldState.text.toString())
//    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "Hello $name!",
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    WeatherAppTheme {
        Greeting("Android")
    }
}