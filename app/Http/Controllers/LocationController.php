<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Location;

class LocationController extends Controller
{
    // Save location data
    public function store(Request $request)
    {
        $location = Location::create([
            'lat' => $request->lat,
            'lng' => $request->lng,
            'speed' => $request->speed,
            'acceleration' => $request->acceleration,
        ]);

        return response()->json(['success' => true]);
    }

    // Get latest location
    public function latest()
    {
        return Location::latest()->first();
    }
}