# 🚗 Detection of Driving Pattern & Live Vehicle Tracking

A full-stack academic project for **real-time vehicle tracking** and **driving behavior analysis**.  
The system ingests live GPS telemetry, persists trip data, exposes REST APIs, visualizes vehicle position on a map, and performs offline driving-pattern analysis using C++.

---

## 📌 Overview

This project demonstrates an end-to-end pipeline for vehicle telemetry:

**Client / Sensor → Laravel REST API → MySQL → Frontend Visualization**

Additionally, a standalone **C++ module** analyzes speed samples to detect:

- Harsh acceleration / braking  
- Aggressive vs normal driving behavior  

The goal is to simulate how real-world telematics systems collect data, process driving signals, and present insights.

---

## 🛠 Tech Stack

### Backend
- **Laravel (PHP)** – REST API, MVC architecture
- **MySQL** – Persistent storage for location and driving metrics

### Frontend
- **HTML / CSS / JavaScript**
- **Google Maps API** – Live vehicle visualization

### Analytics
- **C++** – Driving-pattern classification using STL containers and numeric thresholds

### Realtime (Prototype)
- **Firebase** – Explored for live streaming of location updates

---

## ✨ Key Features

### Backend (Laravel + MySQL)
- REST APIs to ingest GPS telemetry:
  - Latitude
  - Longitude
 
