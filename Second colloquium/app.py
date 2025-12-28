from flask import Flask, jsonify, abort, request, render_template
from datetime import datetime

app = Flask(__name__)

tasks = []
next_id = 1

# ========== ОСНОВНЫЕ ЭНДПОИНТЫ ==========

@app.route('/')
def home():
    return render_template('dashboard.html')

@app.route('/sendtask', methods = ['POST'])
def create_task():
    global next_id

    try:
        data = request.get_json()

        if not data:
            return jsonify({"error": "No data provided"}), 400
            
        new_task = {
            'id': next_id,
            'title': data['title'].strip(),
            'description': data.get('description', '').strip(),
            'status': 'active',
            'created_at': datetime.now()
        }

        print(f"📝 Создана задача: {new_task}")
        print(f"📊 Всего задач: {len(tasks)}")

        tasks.append(new_task)
        next_id += 1

        return jsonify(new_task), 201

    except Exception as e:
        # любые ошибки
        return jsonify({"error": str(e)}), 500


# ========== ОБРАБОТЧИКИ ОШИБОК ==========

@app.errorhandler(404)
def not_found(error):
    return jsonify({
        "status": "error",
        "message": error.description
    }), 404

@app.errorhandler(400)
def bad_request(error):
    return jsonify({
        "status": "error", 
        "message": error.description
    }), 400

@app.errorhandler(500)
def internal_error(error):
    return jsonify({
        "status": "error",
        "message": "Internal server error"
    }), 500


# ========== ЗАПУСК ==========

if __name__ == '__main__':
    print("🚀 To-Do API запущен!")
    print("🛑 Остановить: Ctrl+C")
    app.run(host='0.0.0.0', port=5000, debug=True)

