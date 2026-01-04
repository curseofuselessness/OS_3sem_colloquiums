from flask import Flask, jsonify, abort, request, render_template
from datetime import datetime

app = Flask(__name__)

tasks = []
next_id = 1

# ========== ОСНОВНЫЕ ЭНДПОИНТЫ ==========

@app.route('/')
def home():
    return render_template('dashboard.html', tasks=tasks)

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
            'created_at': datetime.now(),
            'deadline': data['date'].strip()
        }

        print(f"📝 Создана задача: {new_task}")
        print(f"📊 Всего задач: {len(tasks)}")

        tasks.append(new_task)
        next_id += 1

        html = render_template('task.html', task=new_task)

        return jsonify({
            'success': True,
            'message': 'Задача создана',
            'html': html,
            'task': new_task
        }), 201

    except Exception as e:
        # любые ошибки
        return jsonify({"error": str(e)}), 500

@app.route('/deletetask/<int:task_id>', methods = ['delete'])
def delete_task(task_id):

    global tasks 

    task_index = None
    for i, task in enumerate(tasks):
        if task['id'] == task_id:
            task_index = i
            break

    if task_index is None:
            return jsonify({"error": f"Task with id {task_id} not found"}), 404
    
    deleted_task = tasks.pop(task_index)

    print(f"🗑️ Удалена задача: {deleted_task}")
    print(f"📊 Осталось задач: {len(tasks)}")

    return jsonify({
        "success": True,
        "message": f"Task {task_id} deleted",
        "task": deleted_task
    })

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

