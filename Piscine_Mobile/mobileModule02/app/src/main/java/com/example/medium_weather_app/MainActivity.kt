package com.example.medium_weather_app

import android.Manifest
import android.app.Activity
import android.content.Context
import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import android.os.Bundle
import android.provider.Settings
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.ManagedActivityResultLauncher
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.heightIn
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.statusBarsPadding
import androidx.compose.foundation.pager.HorizontalPager
import androidx.compose.foundation.pager.PagerState
import androidx.compose.foundation.pager.rememberPagerState
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.text.KeyboardActions
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.foundation.text.input.TextFieldState
import androidx.compose.foundation.text.input.clearText
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.Badge
import androidx.compose.material3.BadgedBox
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.NavigationBar
import androidx.compose.material3.NavigationBarItem
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.sp
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.CalendarViewWeek
import androidx.compose.material.icons.filled.Timer
import androidx.compose.material.icons.filled.Today
import androidx.compose.material.icons.outlined.CalendarViewWeek
import androidx.compose.material.icons.outlined.Navigation
import androidx.compose.material.icons.outlined.Timer
import androidx.compose.material.icons.outlined.Today
import androidx.compose.material3.ListItem
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.SearchBar
import androidx.compose.material3.SearchBarDefaults
import androidx.compose.material3.Surface
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.ui.Alignment
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.RectangleShape
import androidx.compose.ui.graphics.Shape
import androidx.compose.ui.graphics.graphicsLayer
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.semantics.isTraversalGroup
import androidx.compose.ui.semantics.semantics
import androidx.compose.ui.semantics.traversalIndex
import androidx.compose.ui.text.input.ImeAction
import androidx.compose.ui.unit.dp
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.lifecycle.viewModelScope
import com.example.medium_weather_app.ui.theme.Medium_weather_appTheme
import com.google.android.gms.location.LocationServices
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import kotlinx.serialization.json.Json
import kotlinx.serialization.json.jsonArray
import kotlinx.serialization.json.jsonObject
import kotlinx.serialization.json.jsonPrimitive
import okhttp3.Call
import okhttp3.Callback
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.Response
import org.json.JSONObject
import java.io.IOException


data class TabBarItem(
    val title: String,
    val selectedIcon: ImageVector,
    val unselectedIcon: ImageVector,
    val APIDetails : String,
    val badgeAmount: Int? = null
)

data class Location(
    val Lat: String,
    val Lon: String,
    val Name: String,
    val State: String,
    val Country: String,
    val Timezone: String
)

class WeatherViewModel() : ViewModel() {

    val currentlyTab = TabBarItem(title = "Currently", selectedIcon = Icons.Filled.Timer, unselectedIcon = Icons.Outlined.Timer, APIDetails = "current=temperature_2m,weather_code,wind_speed_10m")
    val todayTab = TabBarItem(title = "Today", selectedIcon = Icons.Filled.Today, unselectedIcon = Icons.Outlined.Today, APIDetails = "hourly=temperature_2m,weather_code,wind_speed_10m&forecast_days=1")
    val weeklyTab = TabBarItem(title = "Weekly", selectedIcon = Icons.Filled.CalendarViewWeek, unselectedIcon = Icons.Outlined.CalendarViewWeek, APIDetails = "&daily=temperature_2m_max,temperature_2m_min,weather_code")
    val tabBarItems = listOf(currentlyTab, todayTab, weeklyTab)


//    val searchResultParsed: List<String>
    var searchResult = mutableStateListOf<Location>()
    var searchResultSelected: Location? by mutableStateOf(null)
    fun updateSearchResultSelected (str : String) {
        searchResultSelected = str
    }

    fun set_SearchResult(value: String) {
        searchResult.clear()
        val json = Json.parseToJsonElement(value).jsonObject
        val array = json["results"]!!.jsonArray
        for (elem in array) {
            val obj = elem.jsonObject
            val city = Location (
                Lat = obj["latitude"]!!.jsonPrimitive.content,
                Lon = obj["longitude"]!!.jsonPrimitive.content,
                Name = obj["name"]!!.jsonPrimitive.content,
                State = obj["admin1"]!!.jsonPrimitive.content,
                Country = obj["country"]!!.jsonPrimitive.content,
                Timezone = obj["timezone"]!!.jsonPrimitive.content,
            )
            searchResult.add(city)
            Log.d("City found: ", obj["name"]!!.jsonPrimitive.content + ", " + obj["admin1"]!!.jsonPrimitive.content + ", " + obj["country"]!!.jsonPrimitive.content)
        }
    }

//    val city by mutableListOf<String>()

    var locationGranted = false

    fun fetchLocation(context: Context) {
        val hasPermission = ActivityCompat.checkSelfPermission(context,Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
        if (!hasPermission) {
            setLocationDenied()
            return
        }

        viewModelScope.launch {
            val client = LocationServices.getFusedLocationProviderClient(context)
            client.lastLocation.addOnSuccessListener { location ->
                if (location != null)
                    updateSearchResultSelected("${location.latitude}, ${location.longitude}")
                else
                    updateSearchResultSelected("Geolocation API Failure")
            }
        }
    }

    fun setLocationDenied() {
        updateSearchResultSelected("Geolocation is not available. Please enable it in your App settings")
    }

//    https://api.open-meteo.com/v1/forecast?latitude=52.484315&longitude=13.4500052&hourly=temperature_2m
    fun fetchCitySearch(city: String) {
        viewModelScope.launch {
            try {
                val result = withContext(Dispatchers.IO) {
                    fetchUrl("https://geocoding-api.open-meteo.com/v1/search?name=$city&count=5")
                }
                set_SearchResult(result)  // back on Main thread
            } catch (e: Exception) {
                updateSearchResultSelected("Connection failed")
            }
        }
    }


    private val client = OkHttpClient()
    suspend fun fetchUrl(url: String): String {
        val request = Request.Builder().url(url).build()
        return withContext(Dispatchers.IO) {
            val response = client.newCall(request).execute()
            response.body?.string() ?: ""
        }
    }
}


class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            Medium_weather_appTheme {
                val context = LocalContext.current
                val viewModel: WeatherViewModel = viewModel()
                val pagerState = rememberPagerState(pageCount = { viewModel.tabBarItems.size })

                val locationPermissionLauncher = rememberLauncherForActivityResult(
                    contract = ActivityResultContracts.RequestPermission()
                ) { isGranted ->
                    if (isGranted) {
                        viewModel.locationGranted = true
                        viewModel.fetchLocation(context)
                    } else {
                        viewModel.locationGranted = false
                        viewModel.setLocationDenied()
                    }
                }
                LaunchedEffect(Unit) {
                    locationPermissionLauncher.launch(Manifest.permission.ACCESS_FINE_LOCATION)
                }
                Box(modifier = Modifier.fillMaxSize()) {
                    Scaffold(
                        topBar = { TopAppBar(viewModel, locationPermissionLauncher) },
                        bottomBar = { BottomNavBar(viewModel.tabBarItems, pagerState) }
                    ) { innerPadding ->
                        HorizontalPager(modifier = Modifier
                            .fillMaxWidth()
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
                    val query = remember { TextFieldState() }

                    SimpleSearchBar(
                        modifier = Modifier
                            .fillMaxWidth(0.85f)
                            .padding(horizontal = 8.dp)
                            .statusBarsPadding(),
                        textFieldState = query,
                        onSearch = { searchText ->
                            viewModel.fetchCitySearch(searchText)
//                        Log.d("Search --> ", viewModel.searchResult)
                        },
                        searchResults = viewModel.searchResult,
                        viewModel = viewModel
                    )
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
                lineHeight = 40.sp,
                textAlign = TextAlign.Center
            )
        }
    }
}
@Composable
fun CurrentlyScreen(viewModel: WeatherViewModel) {
    val title = "Currently"
    val subtitle = viewModel.searchResultSelected.takeIf { it.isNotBlank() } // null if empty
    PrintName(title = title, subtitle = subtitle)
}
@Composable
fun TodayScreen(viewModel: WeatherViewModel) {
    val title = "Today"
    val subtitle = viewModel.searchResultSelected.takeIf { it != null } // null if empty
    PrintName(title = title, subtitle = subtitle)
}
@Composable
fun WeeklyScreen(viewModel: WeatherViewModel) {
    val title = "Weekly"
    val subtitle = viewModel.searchResultSelected.takeIf { it.isNotBlank() } // null if empty
    PrintName(title = title, subtitle = subtitle)
}


@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TopAppBar(
    viewModel: WeatherViewModel,
    locationPermissionLauncher: ManagedActivityResultLauncher<String, Boolean>,
    modifier: Modifier = Modifier
) {
    val context = LocalContext.current
    val shouldShowRationale = ActivityCompat.shouldShowRequestPermissionRationale(
        context as Activity,
        Manifest.permission.ACCESS_FINE_LOCATION
    )
    val hasPermission = ContextCompat.checkSelfPermission(
        context,
        Manifest.permission.ACCESS_FINE_LOCATION
    ) == PackageManager.PERMISSION_GRANTED

    Surface(
        color = MaterialTheme.colorScheme.primaryContainer,
        tonalElevation = 4.dp
    ) {
        Row( modifier
            .fillMaxWidth()
            .height(100.dp)
            .statusBarsPadding()
            .padding(start = 8.dp, end = 8.dp),
            verticalAlignment = Alignment.CenterVertically,
            horizontalArrangement = Arrangement.SpaceEvenly
        ) {
            Box (
                modifier
                    .fillMaxWidth(0.85f)
            ) {}
            Icon(
                imageVector = Icons.Outlined.Navigation,
                contentDescription = "Navigation",
                modifier = Modifier.size(36.dp)
                    .fillMaxWidth(0.15f)
                    .graphicsLayer {
                        this.rotationX = 0f
                        this.rotationY = 0f
                        this.rotationZ = 45f
                    }
                    .clickable {
                        when {
                            hasPermission -> {viewModel.fetchLocation(context)}
                            shouldShowRationale -> {locationPermissionLauncher.launch(Manifest.permission.ACCESS_FINE_LOCATION)}
                            else -> {
                                viewModel.setLocationDenied()
                                val intent = Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS)
                                intent.data = Uri.fromParts("package", context.packageName, null)
                                context.startActivity(intent)
                            }
                        }
                    },
            )
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
    searchResults: List<String>,
    viewModel: WeatherViewModel,
    modifier: Modifier = Modifier
) {
    // Controls expansion state of the search bar
    var expanded by rememberSaveable { mutableStateOf(false) }

    Box(
        Modifier
            .fillMaxWidth()
            .semantics { isTraversalGroup = true }
    ) {
        SearchBar(
            modifier = modifier
                .fillMaxWidth()
                .align(Alignment.TopStart)
                .semantics { traversalIndex = 0f }
                .then(
                    if (expanded)
                        Modifier
                            .heightIn(max = 350.dp)
//                            .background(Color.Gray)
                    else Modifier
//                        .background(Color.Transparent)

                ),
            colors = SearchBarDefaults.colors(
                containerColor = Color.Transparent,
                dividerColor = Color.Transparent,
//                containerColor = Color.Black.copy(alpha = 0.4f),
            ),
            inputField = {
                SearchBarDefaults.InputField(
                    query = textFieldState.text.toString(),
                    onQueryChange = {newKey ->
                        textFieldState.edit { replace(0, length, newKey) }
                        if (newKey.length > 2)
                            onSearch(textFieldState.text.toString())},
                    onSearch = {
                        onSearch(textFieldState.text.toString())
                        expanded = false
                    },
                    expanded = expanded,
                    onExpandedChange = { expanded = it },
                    placeholder = { Text("Search") }
                )
            },
            expanded = expanded,
            onExpandedChange = { expanded = it },
        ) {
            // Display search results in a scrollable column
            Column(Modifier.verticalScroll(rememberScrollState())) {
                searchResults.forEach { result ->
                    Log.d("Each result from city API", result)
                    ListItem(
                        headlineContent = { Text(result) },
                        modifier = Modifier
                            .clickable {
                                textFieldState.edit { replace(0, length, "") }
                                viewModel.searchResultSelected = result
                                viewModel.searchResult.clear()
                                expanded = false
                            }
                            .fillMaxWidth()
                    )
                }
            }
        }
    }
}



@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    Medium_weather_appTheme {
        val context = LocalContext.current
        val viewModel: WeatherViewModel = viewModel()
        val pagerState = rememberPagerState(pageCount = { viewModel.tabBarItems.size })

        val locationPermissionLauncher = rememberLauncherForActivityResult(
            contract = ActivityResultContracts.RequestPermission()
        ) { isGranted ->
            if (isGranted) {
                viewModel.locationGranted = true
                viewModel.fetchLocation(context)
            } else {
                viewModel.locationGranted = false
                viewModel.setLocationDenied()
            }
        }
        LaunchedEffect(Unit) {
            locationPermissionLauncher.launch(Manifest.permission.ACCESS_FINE_LOCATION)
        }
        Box(modifier = Modifier.fillMaxSize()) {
            Scaffold(
                topBar = { TopAppBar(viewModel, locationPermissionLauncher) },
                bottomBar = { BottomNavBar(viewModel.tabBarItems, pagerState) }
            ) { innerPadding ->
                HorizontalPager(modifier = Modifier
                    .fillMaxWidth()
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
            val query = remember { TextFieldState() }

            SimpleSearchBar(
                modifier = Modifier
                    .fillMaxWidth(0.85f)
                    .padding(horizontal = 8.dp)
                    .statusBarsPadding(),
                textFieldState = query,
                onSearch = { searchText ->
                    viewModel.fetchCitySearch(searchText)
//                        Log.d("Search --> ", viewModel.searchResult)
                },
                searchResults = viewModel.searchResult,
                viewModel = viewModel
            )
        }
    }

}